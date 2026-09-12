package com.mycompany.quadradomagico;

public class Tabuleiro {
    
    private int[][] tabuleiro;
    private int numerodejogadas;
 
    public Tabuleiro() {
        this.tabuleiro = new int[3][3];
        numerodejogadas=0;
    }

    public boolean fazJogada(int linha, int coluna, int numero) {
        if(numero==0)
            return false;
        if (tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = numero;   
            numerodejogadas+=1;      
            return true;
        }
        return false;
    }
    
    //1 para jogo certo, 0 para jogo errado
    public boolean verificaFimDeJogo() {
        int aux;

        //verifica a soma das linhas
        for (int i = 0; i < tabuleiro.length; i++) {
            aux = 0;
            for (int j = 0; j < tabuleiro[0].length; j++) {
                aux += tabuleiro[i][j];
            }
            if (aux != 15) {
                return false;
            }
        }

        //verifica a soma das colunas
        for (int j = 0; j < tabuleiro[0].length; j++) {
            aux = 0;

            for (int i = 0; i < tabuleiro.length; i++) {
                aux += tabuleiro[i][j];
            }
            if (aux != 15) {
                return false;
            }
        }

        //verificação das diagonais, também poderia usar um ciclo for, porém não ajudaria tanto
        if ((tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2]) != 15) {
            return false;
        }

        if ((tabuleiro[2][0] + tabuleiro[1][1] + tabuleiro[0][2]) != 15) {
            return false;
        }
        
        //caso não tenha um vencedor, o jogo acaba na nona jogada valida
 
        return true;
    }
}
