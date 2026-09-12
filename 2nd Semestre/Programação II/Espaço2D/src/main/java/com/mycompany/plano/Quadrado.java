package com.mycompany.plano;
public class Quadrado extends Forma {
    private final double lado1;
    private final double lado2;
    private final double lado3;
    private final double lado4;
    
    public Quadrado(double lado1,double lado2,double lado3,double lado4){
        super();
        this.lado1=lado1;
        this.lado2=lado2;
        this.lado3=lado3;
        this.lado4=lado4;
    }

    @Override
    public double obterArea() {
        double area;
        area=lado1*lado2;
        return area;
    }

    @Override
    public double calculaPerimetro() {
        double perimetro;
        perimetro=lado1*4;
        return perimetro;
    }
    
    
    
    
}
