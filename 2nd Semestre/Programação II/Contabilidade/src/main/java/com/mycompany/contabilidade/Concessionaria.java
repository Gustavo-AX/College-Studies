package com.mycompany.contabilidade;

public class Concessionaria extends Conta{
    
     public Concessionaria (int dia, int mes, double valor){
        super(dia, mes, valor);   
    }
    
    @Override
    public double getValoraPagar(int diaPagto, int mesPagto) {
        return this.valor;
    }
}
