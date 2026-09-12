package com.mycompany.zull;

import java.util.Scanner;
// conforme combinado, o programa está preparado para receber uma interface grafica
//ou seja, todas as saidas de dados (nesse caso, os prints) estao aqui. 
//O comando adicional é "dance".
//o programa tá perfeito? nem de longe, mas é o que temos para hoje
//para facilitar minha vida eu coloquei a abertura dos arquivos na classe Parser
//sendo assim, ALTERE A LOCALIZAÇÃO DO ARQUIVO NA CLASSE PARSER

public class Zull {
	public static void main(String[] args){
                Scanner entrada = new Scanner(System.in);
                boolean validador=false;
                String aux;
                  
                System.out.println("você deseja jogar com o último log? 'S' or 'n'\n(lembre-se "
                        + "de alterar a localização do arquivo na classe Parser\n"
                        + "certifique-se também que o arquivo existe e tem os comandos certos, se não, vai dar erro");
                aux=entrada.nextLine();
                if("S".equals(aux) || "s".equals(aux)){
                validador = true;
                }
                             
		Game game = new Game();
                System.out.println(game.printWelcome());
                while(true){
                aux=game.play(validador);
                System.out.println(aux);
                if(aux.equals("Thank you for playing.  Good bye."))
                break;
                }
               
                
            }	
}
