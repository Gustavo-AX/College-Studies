package com.mycompany.plano;

import java.util.ArrayList;


 class Espaco2D {
     private final ArrayList<Forma> formas;
     
      public Espaco2D(){
          formas=new ArrayList();
      }
    
    public Forma criaForma(Ponto2D[] pontos){
        return Forma.geraForma(pontos);
    }
    
    public boolean adcionaForma(Forma forma){
         return formas.add(forma);
    }
    
    public double calculaAreaTotal(){
        double aux=0;
        for (Forma forma : formas){
            aux = aux + forma.obterArea();
        }
        return aux;
    }
    
    public double calculaPerimetroTotal(){
        double aux = 0;
        for (Forma forma : formas) {
        aux= aux+forma.calculaPerimetro();
        }
        return aux;
    }
    
    public String mostraTipoTriangulos(){
        int aux = formas.size() - 1;
            if (formas.get(aux) instanceof Triangulo auxiliar){
                return auxiliar.tipoTriangulo(); 
            }
        return null;
        }
    }

 


