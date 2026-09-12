package com.mycompany.mesa;

import java.security.SecureRandom;

public class Baralho {
    private Carta[] baralho;
    private String[] naipes = {"Copas","Ouros","Paus","Espadas"};
    private SecureRandom gerador = new SecureRandom();
    
    public Baralho(){
    baralho=new Carta[52];
    int indice=0;
    for(int j=0; j<naipes.length;j++){
    for(int i=0;i<=12;i++){
        baralho[indice] = new Carta(i+1,naipes[j]);
        indice++;
    }
    }
    }
    
    public void embaralhar(){
        int posicao;
        Carta aux;
        for(int i=0;i<baralho.length;i++){
        posicao=gerador.nextInt(52);
        aux = baralho[posicao];
        baralho[posicao]=baralho[i];
        baralho[i]=aux;
        }
    }
    
    public Carta[] distribuirCarta(int quantidade){
        Carta[] aux = new Carta[quantidade];
        int posicao=0;
        for (int i=0; i<baralho.length;i++){
            if(baralho[i]!= null){
                aux[posicao]=baralho[i];
                baralho[i]=null;
                posicao++;
            }
            if(posicao>=quantidade){
                return aux;
            }
            
        }
        System.out.println("não há mais cartas para serem distribuidas, você quebrou o jogo");
        return null;
    }
}
    

    

