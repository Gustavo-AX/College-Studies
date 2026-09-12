package com.mycompany.zull;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * This class is the main class of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 * 
 * This parser reads user input and tries to interpret it as an "Adventure"
 * command. Every time it is called it reads a line from the terminal and
 * tries to interpret the line as a two word command. It returns the command
 * as an object of class Command.
 *
 * The parser has a set of known command words. It checks user input against
 * the known commands, and if the input is not one of the known commands, it
 * returns a command object that is marked as an unknown command.
 * 
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */
class Parser {

    private CommandWords commands;  // holds all valid command words
    private ManArqTexto manArqTexto;
    private ArrayList<String> texto;
    private static int i;
    private static String auxiliar="";
    
    public Parser() {
        commands = new CommandWords();      
    }
    
    public Command getCommand() {
        String inputLine = "";   // will hold the full input line
        Command aux;

        System.out.print("> ");     // print prompt
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            inputLine = reader.readLine();
        } catch (java.io.IOException exc) {
            System.out.println("There was an error during reading: "
                    + exc.getMessage());
        }
        
        aux=commands.isCommand(inputLine);
        if(aux.getSecondWord()!=null)
        auxiliar+= aux.getCommandWord()+" "+aux.getSecondWord()+"\n";
        if(aux.getSecondWord()==null)
            auxiliar+= aux.getCommandWord()+"\n";
        return (aux);
    }
    
    public void gravarEmArquivo(){
        manArqTexto=new ManArqTexto();
        manArqTexto.abrirArquivoGravacao("/home/gustavo/netbeans-14/zull/logs.txt");
        manArqTexto.gravarLinhaArquivo(auxiliar);
        manArqTexto.fecharArquivoGravacao();
    }
    
    public Command getCommandfromArq(){
        manArqTexto=new ManArqTexto();
        texto=new ArrayList<>();
        String aux;
        
        manArqTexto.abrirArquivoLeitura("/home/gustavo/netbeans-14/zull/logs.txt");
        texto=manArqTexto.lerArquivo();
        aux=texto.get(i);
        i++;
        System.out.println(aux+"\n");//esse vai sair aq mesmo :)
        return (commands.isCommand(aux));
    }
}
