package com.mycompany.contabilidade;

public class AssalariadoComissionado extends Comissionado{
    private double percentualBonus=0.10;

    public AssalariadoComissionado(double percentualBonus, double valorVendas, String nome, String sobrenome, int numIdent) {
        super(valorVendas, nome, sobrenome, numIdent);
        this.percentualBonus = percentualBonus;
    }

    @Override
    public double getValoraPagar(int diaPagto, int mesPagto) {
        return ((Passivo.SALARIO* percentualBonus) + getValorVendas()*0.06);
    }
}
