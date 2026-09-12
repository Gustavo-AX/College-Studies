package com.mycompany.contabilidade;

public class Comissionado extends Empregado {
    private double valorVendas;

    public Comissionado(double valorVendas, String nome, String sobrenome, int numIdent) {
        super(nome, sobrenome, numIdent);
        this.valorVendas = valorVendas;
    }

    public double getValorVendas() {
        return valorVendas;
    }

    @Override
    public double getValoraPagar(int diaPagto, int mesPagto) {
        return (this.valorVendas * 0.06);
    }
      
}
