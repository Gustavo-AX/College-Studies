package com.mycompany.jogo;

public class JogoDaVelha {

    private int[][] tabuleiro;
    private int vencedor, numerodejogadas;
 
    public JogoDaVelha() {
        this.tabuleiro = new int[3][3];
        numerodejogadas=0;
    }

    public boolean fazJogada(int linha, int coluna, int jogador) {
        if (tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = jogador;
            //aqui eu declaro o vencedor, jogador 1 ou 2, isso por que se verificado o fim do jogo
            //o ganhador sera o que fez a ultima jogada
            if (jogador == 1) 
                vencedor = 1;
            else 
                vencedor = 2;
            
            numerodejogadas+=1;
            
            return true;
        }

        return false;
    }

    
    //eu deixei esse print fora da main por que isso é apenas um texte
    public void printTabuleiro() {
        for (int i = 0; i < tabuleiro.length; i++) {
            for (int j = 0; j < tabuleiro[0].length; j++) {
                System.out.print(tabuleiro[i][j] + " ");

            }
            System.out.print("\n");
        }

    }

    public boolean verificaFimDeJogo() {
        int aux;

        //verifica a soma das linhas
        for (int i = 0; i < tabuleiro.length; i++) {
            aux = 1;
            for (int j = 0; j < tabuleiro[0].length; j++) {
                aux *= tabuleiro[i][j];
            }
            if (aux == 1 || aux == 8) {
                return true;
            }
        }

        //verifica a soma das colunas
        for (int j = 0; j < tabuleiro[0].length; j++) {
            aux = 1;

            for (int i = 0; i < tabuleiro.length; i++) {
                aux *= tabuleiro[i][j];
            }
            if (aux == 1 || aux == 8) {
                return true;
            }
        }

        //verificação das diagonais, também poderia usar um ciclo for, porém não ajudaria tanto
        if ((tabuleiro[0][0] * tabuleiro[1][1] * tabuleiro[2][2]) == 1
                || (tabuleiro[0][0] * tabuleiro[1][1] * tabuleiro[2][2]) == 8) {
            return true;
        }

        if ((tabuleiro[2][0] * tabuleiro[1][1] * tabuleiro[0][2]) == 1
                || (tabuleiro[2][0] * tabuleiro[1][1] * tabuleiro[0][2]) == 8) {
            return true;
        }
        
        //caso não tenha um vencedor, o jogo acaba na nona jogada valida
        if(numerodejogadas==9)
            return true;

        return false;
    }
}
