package com.mycompany.contabilidade;

public abstract class Empregado implements Passivo{

    public Empregado(String nome, String sobrenome, int numIdent) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.numIdent = numIdent;
    }
    
    protected String nome;
    protected String sobrenome;
    protected int numIdent;
}
