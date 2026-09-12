package com.mycompany.contabilidade;

public class Terceirizado extends Empregado{
    private double horasTrabalhadas;

    public Terceirizado(double horasTrabalhadas, String nome, String sobrenome, int numIdent) {
        super(nome, sobrenome, numIdent);
        this.horasTrabalhadas = horasTrabalhadas;
    }

    @Override
    public double getValoraPagar(int diaPagto, int mesPagto) {
        return (Passivo.HORA * horasTrabalhadas);
    }
    
}
