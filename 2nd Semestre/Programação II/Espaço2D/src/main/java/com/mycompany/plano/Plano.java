package com.mycompany.plano;

public class Plano {

    public static void main(String[] args) {
        System.out.println("Bem vindo ao espaço 2D");
        Espaco2D espaco = new Espaco2D();

        Ponto2D[] pontoscirculo = new Ponto2D[2];
        pontoscirculo[0] =new Ponto2D(0,0);
        pontoscirculo[1] =new Ponto2D(1,0);
        if(espaco.adcionaForma(espaco.criaForma(pontoscirculo)))
        System.out.println("figura adicionada");
    
        Ponto2D[] pontostriangulo = new Ponto2D[3];
        pontostriangulo[0] =new Ponto2D(0,0);
        pontostriangulo[1] =new Ponto2D(1,0);
        pontostriangulo[2] =new Ponto2D(1,1);
        if(espaco.adcionaForma(espaco.criaForma(pontostriangulo)))
            System.out.println("triangulo " + espaco.mostraTipoTriangulos() + " adicionado");

        Ponto2D[] pontostriangulo1 = new Ponto2D[3];
        pontostriangulo1[0] =new Ponto2D(0,0);
        pontostriangulo1[1] =new Ponto2D(1,0);
        pontostriangulo1[2] =new Ponto2D(1,3);
        if(espaco.adcionaForma(espaco.criaForma(pontostriangulo1)))
            System.out.println("triangulo " + espaco.mostraTipoTriangulos() + " adicionado");

        Ponto2D[] pontosquadrado = new Ponto2D[4];
        pontosquadrado[0] =new Ponto2D(0,0);
        pontosquadrado[1] =new Ponto2D(1,0);
        pontosquadrado[2] =new Ponto2D(1,1);
        pontosquadrado[3] =new Ponto2D(0,1);
        if(espaco.adcionaForma(espaco.criaForma(pontosquadrado)))
            System.out.println("figura adicionada");


        System.out.println("area total: " + espaco.calculaAreaTotal());
        System.out.println("PERIMETRO total: " + espaco.calculaPerimetroTotal()); 
    }
}
