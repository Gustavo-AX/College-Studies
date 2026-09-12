#include "Catch.h"
#include "ui_Catch.h"
#include "Player.h"

#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include <QActionGroup>
#include <QSignalMapper>

Catch::Catch(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Catch),
      m_player(Player::player(Player::Red))
{

    ui->setupUi(this);

    QObject::connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(reset()));
    QObject::connect(ui->actionQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));

    QSignalMapper *map = new QSignalMapper(this);
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            QString cellName = QString("cell%1%2").arg(row).arg(col);
            Cell *cell = this->findChild<Cell *>(cellName);
            Q_ASSERT(cell != nullptr);
            Q_ASSERT(cell->row() == row && cell->col() == col);

            m_board[row][col] = cell;

            int id = row * 8 + col;
            map->setMapping(cell, id);
            QObject::connect(cell, SIGNAL(clicked(bool)), map, SLOT(map()));
            QObject::connect(cell, SIGNAL(mouseOver(bool)), this, SLOT(updateSelectables(bool)));
        }
    }
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QObject::connect(map, SIGNAL(mapped(int)), this, SLOT(play(int)));
#else
    QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(play(int)));
#endif

    // When the turn ends, switch the player.
    QObject::connect(this, SIGNAL(turnEnded()), this, SLOT(switchPlayer()));

    this->reset();

    this->adjustSize();
    this->setFixedSize(this->size());
}

Catch::~Catch()
{
    delete ui;
}

void Catch::play(int id)
{
    Cell *cell = m_board[id / 8][id % 8];
    if (cell == nullptr || !cell->isSelectable())
        return;

    // Define nextCell according to orientation
    Cell *nextCell = nullptr;
    // If the orientation is vertical, cell just can go until the row 7
    if (m_player->orientation() == Player::Vertical && cell->row() < 7)
    {
        nextCell = m_board[cell->row() + 1][cell->col()];
    }
    else if (m_player->orientation() == Player::Horizontal && cell->col() < 7)
    {
        // If the orientation is horizontal, cell just can go until the col 7
        nextCell = m_board[cell->row()][cell->col() + 1];
    }

    nextCell->setState(Cell::Blocked);
    cell->setState(Cell::Blocked);
    // check if has a cell captured;
    checkGame();
    // check if the game is finished. This function search every possibility
    // of play to the next player:
    if (checkEndGame())
    {
        this->updateStatusBar();
        if (m_player->count() > m_player->other()->count())
        {
            // if the actual player won:
            QMessageBox::information(this, tr(""), tr("Parabéns, o %1 venceu por %2 a %3").arg(m_player->name()).arg(m_player->count()).arg(m_player->other()->count()));
        }
        else if (m_player->count() < m_player->other()->count())
        {
            // if the other player won:
            QMessageBox::information(this, tr(""), tr("Parabéns, o %1 venceu por %2 a %3").arg(m_player->other()->name()).arg(m_player->other()->count()).arg(m_player->count()));
        }
        else
        {
            // if happened a tie:
            QMessageBox::information(this, tr(""), tr("O jogo empatou em %1 a %2").arg(m_player->count()).arg(m_player->count()));
        }
    }

    emit turnEnded();
}

// search for empty cells:
void Catch::checkGame()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Cell *cell = m_board[i][j];
            // if the cell is empty, a look around it
            if (cell->isEmpty())
            {
                checkNeighbor(cell);
                // check if cells in that place is 3 ou less
                if (check.size() <= 3)
                {
                    // if ther is 3 ou less cells, they are captured
                    for (int t = 0; t < check.size(); t++)
                    {
                        check[t]->setPlayer(m_player);
                        check[t]->setState(Cell::Captured);
                        m_player->incrementCount();
                    }
                }
                // erase the vector, to use it in the next cycle
                check.clear();
            }
        }
    }
    // erase the status "checked" of all cells
    clearCheck();
}

// check the neighborhood of the cell, to help me, i create a new state to the cells,
// it name is "checked" and it tell me if the cell is already checked or not.
void Catch::checkNeighbor(Cell *cell)
{
    cell->setState(Cell::Checked);
    check.push_back(cell);
    Cell *nextCell;

    // check the cell in the left, if it exist
    if (cell->col() > 0)
    {
        nextCell = m_board[cell->row()][cell->col() - 1];
        if (!nextCell->isChecked() && !nextCell->isBlocked())
            checkNeighbor(nextCell);
    }
    // check the cell in the right, if it exist
    if (cell->col() < 7)
    {
        nextCell = m_board[cell->row()][cell->col() + 1];
        if (!nextCell->isChecked() && !nextCell->isBlocked())
            checkNeighbor(nextCell);
    }

    // check the cell below, if it exist
    if (cell->row() < 7)
    {
        nextCell = m_board[cell->row() + 1][cell->col()];
        if (!nextCell->isChecked() && !nextCell->isBlocked())
            checkNeighbor(nextCell);
    }
    // check the cell above, if it exist
    if (cell->row() > 0)
    {
        nextCell = m_board[cell->row() - 1][cell->col()];
        if (!nextCell->isChecked() && !nextCell->isBlocked())
            checkNeighbor(nextCell);
    }
}

// erase all cells that have the status "empty":
void Catch::clearCheck()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Cell *cell = m_board[i][j];
            if (cell->isChecked())
            {
                cell->setState(Cell::Empty);
            }
        }
    }
}

bool Catch::checkEndGame()
{
    // if the player is blue(vertical), a check the play of the next player, red (horizontal)
    if (m_player->orientation() == Player::Vertical)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                Cell *cell = m_board[i][j];
                Cell *nextCell = m_board[i][j + 1];
                if (cell->isEmpty() && nextCell->isEmpty())
                {
                    return false;
                }
            }
        }
    }
    else // if the player is red, a look to the next player, blue in that case
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Cell *cell = m_board[i][j];
                Cell *nextCell = m_board[i + 1][j];
                if (cell->isEmpty() && nextCell->isEmpty())
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void Catch::switchPlayer()
{
    // Switch the player.
    m_player = m_player->other();

    // Finally, update the status bar.
    this->updateStatusBar();
}

void Catch::reset()
{
    // Reset board.
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            Cell *cell = m_board[row][col];
            cell->reset();
        }
    }

    // Reset the players.
    Player *red = Player::player(Player::Red);
    red->reset();

    Player *blue = Player::player(Player::Blue);
    blue->reset();

    m_player = red;

    // Finally, update the status bar.
    this->updateStatusBar();
}

void Catch::showAbout()
{
    QMessageBox::information(this, tr("Sobre"), tr("Catch\n\nGustavo de Assis Xavier - gustavoassis203@gmail.com"));
}

void Catch::updateSelectables(bool over)
{
    Cell *cell = qobject_cast<Cell *>(QObject::sender());
    Q_ASSERT(cell != nullptr);
    Cell *nextCell = nullptr;

    // Define nextCell according to orientation
    if (m_player->orientation() == Player::Vertical && cell->row() < 7)
    {
        nextCell = m_board[cell->row() + 1][cell->col()];
    }
    else if (m_player->orientation() == Player::Horizontal && cell->col() < 7)
    {
        nextCell = m_board[cell->row()][cell->col() + 1];
    }

    // set cell selectable
    if (over)
    {
        if (cell->isEmpty() && nextCell != nullptr && nextCell->isEmpty())
        {
            cell->setState(Cell::Selectable);
            nextCell->setState(Cell::Selectable);
        }
    }
    else // turn the selectable cell in empty
    {
        if (cell->isSelectable() && nextCell != nullptr && nextCell->isSelectable())
        {
            cell->setState(Cell::Empty);
            nextCell->setState(Cell::Empty);
        }
    }
}

void Catch::updateStatusBar()
{
    ui->statusbar->showMessage(tr("Vez do %1 (%2 a %3)")
                                   .arg(m_player->name())
                                   .arg(m_player->count())
                                   .arg(m_player->other()->count()));
}

// se cometi um erro no inglês foi culpa do sistema :)