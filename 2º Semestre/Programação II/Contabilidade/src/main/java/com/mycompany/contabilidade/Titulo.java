package com.mycompany.contabilidade;

public class Titulo extends Conta{
    public Titulo (int dia, int mes, double valor){
        super(dia, mes, valor);
    }
    
    @Override
    public double getValoraPagar(int diaPagto, int mesPagto) {
        if((diaPagto>this.dia)&&(mesPagto>=this.mes)){
        return (this.valor*1.1);
    }
        return this.valor;
    }
    
}
