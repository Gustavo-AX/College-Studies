package com.mycompany.mesa;

public class Carta {
    private int valor;
    private String naipe;
    
    public Carta(){
        this.valor = 0;
        this.naipe="";
    }
    public Carta(int valor, String naipe){
        this.valor=valor;
        this.naipe=naipe;
    }
    
    public void setNaipe(String naipe){
        this.naipe=naipe;
    }
    public void setValor(int valor){
        this.valor=valor;
    }
    
    public String getNaipe(){
        return this.naipe;
    }
    public int getValor(){
        return this.valor;
    }
    
    public int compValor(Carta carta){
        if(this.valor>carta.getValor()){
            return 1;
        }
        if(this.valor<carta.getValor()){
            return -1;
        }
            return 0;
        }
    
    //eu não encontrei serventia para esse método no meu programa :(
    public boolean compNaipe(Carta carta){
        if(this.naipe.equals(carta.getNaipe())){
            return true;
        }
        return false;
    }
}
