package com.mycompany.mesa;
import java.util.Scanner;

public class Mesa {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Baralho baralho1 = new Baralho();
        Carta aux1=new Carta();
        Carta aux2=new Carta();
        
        
        while (true) {
            baralho1.embaralhar();
            System.out.println("Mesa embaralhando.........");
        
            
            System.out.println("Informe o número de cartas a distribuir aos jogadores:");
            int aux = entrada.nextInt();
            Jogador jogadorA = new Jogador(aux);
            Jogador jogadorB = new Jogador(aux);
            jogadorA.setMao(baralho1.distribuirCarta(aux));
            jogadorB.setMao(baralho1.distribuirCarta(aux));
            System.out.println("Mesa distribuiu " + aux + " cartas para Jogador A e Jogador B");

            aux1=jogadorA.jogarMaior();
            aux2=jogadorB.jogarMaior();
            
            System.out.println("O jogadorA joga a carta de naipe " + aux1.getNaipe() + " e de valor " + aux1.getValor());
            System.out.println("O jogadorB joga a carta de naipe " + aux2.getNaipe() + " e de valor " + aux2.getValor());

            if (aux1.compValor(aux2)==1){
                System.out.println("jogadorA venceu o jogo");
                break;
            }
            if (aux1.compValor(aux2)==-1){
                System.out.println("jogadorB venceu o jogo");
                break;
            }
            if (aux1.compValor(aux2)==0){
                if (aux1.getNaipe().equals("Ouros")){
                    System.out.println("por ter a carta de ouros, o jogadorA venceu o jogo");
                    break;
                }
                if (aux2.getNaipe().equals("Ouros")){
                    System.out.println("por ter a carta de ouros, o jogadorB venceu o jogo");
                    break;
                }
            }
            System.out.println("o jogo empatou.");
            System.out.println("jogando novamente:");
        }
    }
}
