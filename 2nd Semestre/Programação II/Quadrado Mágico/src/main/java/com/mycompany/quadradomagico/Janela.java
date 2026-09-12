package com.mycompany.quadradomagico;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JToggleButton;

public class Janela extends JFrame implements ActionListener {

    private JPanel north, mid, south;
    private JLabel text;
    private JToggleButton[][] keys;
    private JButton[][] matrix;
    private JButton clear, exit;
    private int aux, contador = 0;
    Tabuleiro t;

    public Janela() {
        super("Agenda de contatos");
        setLayout(new BorderLayout());
        instanciaComponentes();
        adicionaComponentes();
        t = new Tabuleiro();
    }

    private void instanciaComponentes() {
        keys = new JToggleButton[3][3];
        matrix = new JButton[3][3];

        text = new JLabel("A soma de cada linha, coluna e diagonal deve ser 15");

        north = new JPanel();
        north.setLayout(new GridLayout(1, 1));

        mid = new JPanel();
        mid.setLayout(new GridLayout(6, 3));

        south = new JPanel();
        south.setLayout(new GridLayout(1, 1));
        int auxiliar = 0;
        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                auxiliar++;
                keys[i][j] = new JToggleButton(Integer.toString(auxiliar));
                matrix[i][j] = new JButton("0");
                matrix[i][j].setBackground(new java.awt.Color(255, 255, 255));
                keys[i][j].setBackground(new java.awt.Color(153, 255, 153));

                //adiciono os eventos
                keys[i][j].addActionListener(this);
                matrix[i][j].addActionListener(this);
            }

        }
        clear = new JButton("Limpar");
        exit = new JButton("Sair");;

        clear.addActionListener(this);
        exit.addActionListener(this);

    }

    private void adicionaComponentes() {

        add(north, BorderLayout.NORTH);
        add(mid, BorderLayout.CENTER);
        add(south, BorderLayout.SOUTH);

        north.add(text);

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                mid.add(matrix[i][j]);
            }

        }

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                mid.add(keys[i][j]);
            }

        }
        south.add(clear);
        south.add(exit);

    }

    @Override
    public void actionPerformed(ActionEvent ae) {

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                if (ae.getSource() == keys[i][j]) {
                    aux = (i * 3) + (j * 1) + 1;
                }
                if (ae.getSource() == matrix[i][j]) {
                    if (t.fazJogada(i, j, aux)) {
                        matrix[i][j].setText(Integer.toString(aux));
                        contador++;
                        aux = 0;
                    } else {
                        if(aux!=0)
                        keys[(aux - 1) / 3][(aux - 1) % 3].setSelected(false);
                    }

                }
            }

        }

        if (ae.getSource() == clear) {
            limpar();
        }
        
        if (ae.getSource() == exit) {
            System.exit(0);
        }
        
        if(contador==9){
            
            try{
            if(t.verificaFimDeJogo()){
            JOptionPane.showMessageDialog(null, "voce ganhou");
            limpar();
            }
            else{
            throw new Erro();
            }
            }catch(Erro e){
            JOptionPane.showMessageDialog(null, "Não foi dessa vez! Mais sorte na próxima", "Erro", JOptionPane.ERROR_MESSAGE);
            limpar();
            }
        }   
        

    }
    
    public void limpar(){
         t = new Tabuleiro();

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matrix[i][j].setText("0");
                    keys[i][j].setSelected(false);
                    contador=0;
                }
            }
    }

}
