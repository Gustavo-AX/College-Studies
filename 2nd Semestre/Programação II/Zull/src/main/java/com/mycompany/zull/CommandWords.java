package com.mycompany.zull;

import java.util.StringTokenizer;

/*
 * This class is the main class of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 * 
 * This class holds an enumeration of all command words known to the game.
 * It is used to recognise commands as they are typed in.
 *
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */
class CommandWords {

    // a constant array that holds all valid command words
    private static final String validCommands[] = {
        "go", "quit", "help", "look", "procurar","dance"
    };

    /**
     * Constructor - initialise the command words.
     */
    public CommandWords() {
        // nothing to do at the moment...
    }

    /**
     * Check whether a given String is a valid command word. Return true if it
     * is, false if it isn't.
     */
    
    
    
    public Command isCommand(String aString){
        String word1,word2;
        StringTokenizer tokenizer = new StringTokenizer(aString);

        if (tokenizer.hasMoreTokens()) {
            word1 = tokenizer.nextToken();      // get first word
        } else {
            word1 = null;
        }
        if (tokenizer.hasMoreTokens()) {
            word2 = tokenizer.nextToken();      // get second word
        } else {
            word2 = null;
        }
        
        for (String validCommand : validCommands) {
            if (validCommand.equals(word1)) {
                return new Command(word1, word2);
            }
    }
        
        try{
           throw new InvalidCommandException("Comando Inválido"); 
        } catch (InvalidCommandException e){
            System.err.println("Aconteceu um erro:");  
            e.printStackTrace();
        }
        
    return new Command(null, word2);
}
}
