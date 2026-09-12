package com.mycompany.contabilidade;

public class Assalariado extends Empregado {
    private double horasExtras;

    public Assalariado(double horasExtras, String nome, String sobrenome, int numIdent) {
        super(nome, sobrenome, numIdent);
        this.horasExtras = horasExtras;
    }
  
    @Override
    public double getValoraPagar(int diaPagto, int mesPagto) {
        return ((Passivo.SALARIO*1.1)+this.horasExtras*Passivo.HORA);
    }
}
