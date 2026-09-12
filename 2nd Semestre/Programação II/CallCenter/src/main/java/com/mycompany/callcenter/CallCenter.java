package com.mycompany.callcenter;
import java.util.Scanner;
import java.util.HashSet;


public class CallCenter {

    public static void main(String[] args) {
         Scanner entrada = new Scanner(System.in);
         Interpretadora aux=new Interpretadora();
         SuporteTecnico sup=new SuporteTecnico();
         String v = "";
         String problema="";
         
         System.out.println("Bem vindo ao sistema de suporte técnico");
         
         while(true){
         System.out.println("Pressione <enter> para continuar ou digite 'sair' para sair do sistema");
         v=entrada.nextLine();
         if("sair".equals(v))
         break;
         
        System.out.println("Descreva seu problema de forma suscinta.");
        problema=entrada.nextLine();
         
         if(sup.buscaSolucao(aux.interpretaProblema(problema))!=null)
             System.out.println(sup.buscaSolucao(aux.interpretaProblema(problema)));
         else
             System.out.println(sup.respostaPadrao(aux.interpretaProblema(problema))); 
         
         
         System.out.println("");
             }
         
         System.out.println("Obrigado por usar nosso serviços!");
    }
}
