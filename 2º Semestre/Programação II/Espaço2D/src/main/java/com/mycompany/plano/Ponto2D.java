package com.mycompany.plano;

public class Ponto2D {
    
private final double x;
private final double y;

public Ponto2D(){
    this.x=0;
    this.y=0;
}

public Ponto2D(double x, double y){
    this.x=x;
    this.y=y;
}

public Ponto2D(Ponto2D ponto){
    this.x=ponto.getX();
    this.y=ponto.getY();
}

public double getX(){
    return this.x;
}

public double getY(){
    return this.y;
}

public double calculaDistancia(Ponto2D ponto){
    double distancia;
    distancia = Math.sqrt( Math.pow(x-ponto.getX(), 2) + Math.pow(y-ponto.getY() , 2));
    return distancia;
}
}
