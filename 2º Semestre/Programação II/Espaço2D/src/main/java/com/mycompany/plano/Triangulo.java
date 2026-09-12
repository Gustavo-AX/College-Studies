package com.mycompany.plano;
public class Triangulo extends Forma {
    private final double lado1;
    private final double lado2;
    private final double lado3;
    
    public Triangulo(double lado1, double lado2, double lado3){
        super();
        this.lado1=lado1;
        this.lado2=lado2;
        this.lado3=lado3;
    }
    
    public String tipoTriangulo(){
        if(lado1==lado2 && lado2==lado3)
            return "equilatero";
        
        if(lado1==lado2 || lado2==lado3 || lado1 ==lado3)
            return "isoceles";
        
        return "escaleno";  
    }
    
    /**
     *
     * @return
     */
    @Override
    public double obterArea() {
        double sp=(lado1+lado2+lado3)/2;
        double area = Math.sqrt(sp*(sp-lado1)*(sp-lado2)*(sp-lado3));
        return area; 
    }
   
    public double calculaPerimetro() {
        double perimetro;
        perimetro=lado1+lado2+lado3;
        return perimetro;
    }
    
}