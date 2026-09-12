package com.mycompany.callcenter;
import java.util.HashSet;

public class Interpretadora {
    private HashSet<String>palavrasChave;
    
    public Interpretadora(){
        this.palavrasChave=new HashSet<>();
    }
    
    public HashSet<String> interpretaProblema(String queixa){
        palavrasChave.clear();
        String[] palavras = queixa.split(" ");
        for(String aux: palavras){
            this.palavrasChave.add(aux.toLowerCase());
    }
        return this.palavrasChave;
    }
    
}
