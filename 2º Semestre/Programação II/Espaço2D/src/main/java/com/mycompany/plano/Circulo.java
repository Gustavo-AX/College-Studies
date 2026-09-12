package com.mycompany.plano;

public class Circulo extends Forma{
    private final double raio;
    
    public Circulo(double raio){
        super(); 
        this.raio=raio;
    }
    
    @Override
    public double obterArea() {
    double area;
    area = Math.PI * Math.pow(raio , 2);
    return area;
    }
    

    @Override
    public double calculaPerimetro() {
        double perimetro;
        perimetro=2*Math.PI *raio;
        return perimetro;
    }
}

