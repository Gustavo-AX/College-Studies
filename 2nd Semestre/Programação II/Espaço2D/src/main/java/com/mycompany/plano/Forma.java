package com.mycompany.plano;

public abstract class Forma {
    private Ponto2D[] pontos;
    public abstract double obterArea();
    public abstract double calculaPerimetro();
  
    public static Forma geraForma(Ponto2D[] pontos){
        Forma forma=null;
        
        if((pontos.length == 2) && pontos[0].calculaDistancia(pontos[1]) != 0){
            forma = new Circulo(pontos[0].calculaDistancia(pontos[1]));
            forma.setPontos(pontos);
        }    
            
        if(pontos.length == 3){
            double lado1 = pontos[0].calculaDistancia(pontos[1]);
            double lado2 = pontos[1].calculaDistancia(pontos[2]);
            double lado3 = pontos[2].calculaDistancia(pontos[0]);
            if ((lado1+lado2)>lado3){
                forma=new Triangulo (lado1, lado2, lado3);
                 forma.setPontos(pontos);
            }
        }
            
        if(pontos.length == 4){
            double lado1 = pontos[0].calculaDistancia(pontos[1]);
            double lado2 = pontos[1].calculaDistancia(pontos[2]);
            double lado3 = pontos[2].calculaDistancia(pontos[3]);
            double lado4 = pontos[3].calculaDistancia(pontos[0]);
            if((lado1==lado2 && lado2 == lado3 && lado3==lado4))
                forma=new Quadrado(lado1,lado2,lado3,lado4); 
             forma.setPontos(pontos);
        }
            return forma;
    }
    
    public void setPontos(Ponto2D[] pontos){
        this.pontos=pontos;
    }
    
    
}
