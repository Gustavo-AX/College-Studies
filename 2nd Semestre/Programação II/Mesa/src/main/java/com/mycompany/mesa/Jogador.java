package com.mycompany.mesa;

public class Jogador {
private Carta[] mao;

    public Jogador(int quantidade){
    this.mao=new Carta[quantidade];
}

public void setMao(Carta[] mao){
    this.mao=mao;
}

public Carta[] getMao(){
    return this.mao;
}
        
public Carta jogarMaior(){
Carta aux=new Carta();
aux=mao[0];
for(int i=0; i<mao.length;i++){
if(mao[i].compValor(aux)==1)
aux=mao[i];
if((mao[i].compValor(aux)==0) && ((mao[i].getNaipe()).equals("Ouros")))
aux=mao[i];
}
return aux;
}
}
