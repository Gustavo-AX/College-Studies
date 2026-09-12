package com.mycompany.zull;

/**
 * This class is the main class of the "World of Zuul" application. "World of
 * Zuul" is a very simple, text based adventure game. Users can walk around some
 * scenery. That's all. It should really be extended to make it more
 * interesting!
 *
 * To play this game, create an instance of this class and call the "play"
 * method.
 *
 * This main class creates and initialises all the others: it creates all rooms,
 * creates the parser and starts the game. It also evaluates and executes the
 * commands that the parser returns.
 *
 * @author Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */
class Game {

    private Parser parser;
    static private Room currentRoom;

    /**
     * Create the game and initialise its internal map.
     */
    public Game() {
        createRooms();
        parser = new Parser();
    }

    /**
     * Create all the rooms, link their exits together, and create the
     * interactives objects in the room.
     */
    private void createRooms() {
        Room outside, theatre, pub, lab, office, porao, sotao;

        // create the rooms
        outside = new Room("outside the main entrance of the university");

        theatre = new Room("in a lecture theatre");
        theatre.addInterativos(new Interativo("Actors"));

        pub = new Room("in the campus pub");
        pub.addInterativos(new Interativo("a cup of beer"));

        lab = new Room("in a computing lab");
        lab.addInterativos(new Interativo("PC Gamer"));

        office = new Room("in the computing admin office");
        office.addInterativos(new Interativo("Pen"));

        porao = new Room("in the basement");
        porao.addInterativos(new Interativo("A monster in a jail"));
        porao.addInterativos(new Interativo("A sagrade sword"));

        sotao = new Room("in the attic");
        sotao.addInterativos(new Interativo("a very old book, that contains all the truth of the world"
                + "but you aren't ready to read it"));

        // initialise room exits
        outside.setExits(null, theatre, lab, pub, null, null);
        theatre.setExits(null, null, null, outside, null, null);
        pub.setExits(null, outside, null, null, null, null);
        lab.setExits(outside, office, null, null, null, null);
        office.setExits(null, null, null, lab, sotao, porao);
        porao.setExits(null, null, null, null, office, null);
        sotao.setExits(null, null, null, null, null, office);

        currentRoom = outside;  // start game outside
    }

    /**
     * Main play routine. Loops until end of play.
     */
    public String play(boolean validador) {

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
        String aux;
        String finished = "";
        Command command;
             
        if(validador){
            command=parser.getCommandfromArq(); 
        }
        else{
            command = parser.getCommand();
            
        }
        
        finished = processCommand(command);
        if(!finished.equals("quit"))
            return finished;  
        parser.gravarEmArquivo();
        return "Thank you for playing.  Good bye.";
    }

    /**
     * Print out the opening message for the player.
     */
    public String printWelcome() {
        String aux = "";

        /*System.out.println();
        System.out.println("Welcome to Adventure!");
        System.out.println("Adventure is a new, incredibly boring adventure game.");
        System.out.println("Type 'help' if you need help.");
        System.out.println();
        System.out.println("You are " + currentRoom.getDescription());
        System.out.print("Exits: ");*/
        if (currentRoom.rooms[0] != null) {
            //System.out.print("north ");
            aux = aux + "north ";
        }
        if (currentRoom.rooms[1] != null) {
            //System.out.print("east ");
            aux = aux + "east ";
        }
        if (currentRoom.rooms[2] != null) {
            // System.out.print("south ");
            aux = aux + "south ";
        }
        if (currentRoom.rooms[3] != null) {
            //System.out.print("west ");
            aux = aux + "west ";
        }
        if (currentRoom.rooms[4] != null) {
            //System.out.print("up ");
            aux = aux + "up ";
        }
        if (currentRoom.rooms[5] != null) {
            //System.out.print("down ");
            aux = aux + "down ";
        }
        //System.out.println();

        String welcome = "Welcome to Adventure!\n"
                + "Adventure is a new, incredibly boring adventure game.\n"
                + "Type 'help' if you need help.\n"
                + "You are " + currentRoom.getDescription() + "\n"
                + "Exits: \n"
                + aux
                + "\n";

        return welcome;
    }

    /**
     * Given a command, process (that is: execute) the command. If this command
     * ends the game, true is returned, otherwise false is returned.
     */
    private String processCommand(Command command) {
        String wantToQuit = "";

        if (command.isUnknown()) {
            return "I don't know what you mean...";
        }

        String commandWord = command.getCommandWord();
        if (commandWord.equals("help")) {
            wantToQuit = printHelp();
        } else if (commandWord.equals("go")) {
            wantToQuit = goRoom(command);
        } else if (commandWord.equals("quit")) {
            wantToQuit = quit(command);
        } else if (commandWord.equals("procurar")) {
            wantToQuit = procurar();
        } else if (commandWord.equals("dance")) {
            wantToQuit = dance();
        }
        return wantToQuit;
    }

    // implementations of user commands:
    /**
     * Print out some help information. Here we print some stupid, cryptic
     * message and a list of the command words.
     */
    private String printHelp() {
        String printHelp = """
                         You are lost. You are alone. You wander
                         around at the university.
                         
                         Your command words are:
                            go quit help
                         """;
        return printHelp;
    }

    /**
     * Try to go to one direction. If there is an exit, enter the new room,
     * otherwise print an error message.
     */
    private String goRoom(Command command) {
        String goroom = "";
        if (!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            goroom = goroom + "Go where? \n";
            return goroom;
        }

        String direction = command.getSecondWord();

        // Try to leave current room.
        Room nextRoom = null;
        if (direction.equals("north")) {
            nextRoom = currentRoom.rooms[0];
        }
        if (direction.equals("east")) {
            nextRoom = currentRoom.rooms[1];
        }
        if (direction.equals("south")) {
            nextRoom = currentRoom.rooms[2];
        }
        if (direction.equals("west")) {
            nextRoom = currentRoom.rooms[3];
        }
        if (direction.equals("up")) {
            nextRoom = currentRoom.rooms[4];
        }
        if (direction.equals("down")) {
            nextRoom = currentRoom.rooms[5];
        }

        if (nextRoom == null) {
            goroom = goroom + "There is no door!\n";
            return goroom;
        } else {
            currentRoom = nextRoom;
            goroom = goroom + "You are " + currentRoom.getDescription() + "\n"
                    + "the interactives objects in this room are: \n";

            for (Interativo interativo : currentRoom.getInterativos()) {
                goroom = goroom + interativo.getInterativo() + "\n";
            }

            goroom = goroom + ("Exits: ");
            if (currentRoom.rooms[0] != null) {
                goroom += "north ";
            }
            if (currentRoom.rooms[1] != null) {
                goroom += "east ";
            }
            if (currentRoom.rooms[2] != null) {
                goroom += "south ";
            }
            if (currentRoom.rooms[3] != null) {
                goroom += "west ";
            }
            if (currentRoom.rooms[4] != null) {
                goroom += "up ";
            }
            if (currentRoom.rooms[5] != null) {
                goroom += "down ";
            }

            goroom += "\n";
            return goroom;
        }
    }

    private String procurar() {
        String aux_itens = "";
        String aux_saidas = "";
        for (Interativo interativo : currentRoom.getInterativos()) {
            aux_itens = aux_itens + interativo.getInterativo() + "\n";
        }

        if (currentRoom.rooms[0] != null) {
            aux_saidas = aux_saidas + "north ";
        }
        if (currentRoom.rooms[1] != null) {
            aux_saidas = aux_saidas + "east ";
        }
        if (currentRoom.rooms[2] != null) {
            aux_saidas = aux_saidas + "south";
        }
        if (currentRoom.rooms[3] != null) {
            aux_saidas = aux_saidas + "west ";
        }
        if (currentRoom.rooms[4] != null) {
            aux_saidas = aux_saidas + "up ";
        }
        if (currentRoom.rooms[5] != null) {
            aux_saidas = aux_saidas + "down ";
        }

        String procurar = "you are " + currentRoom.getDescription() + "\n"
                + "the interactives objects in this room are:\n"
                + aux_itens
                + "\n"
                + "the exits of this room are: \n"
                + aux_saidas + "\n";
        return procurar;
    }

    private String dance() {
        return "you dance so cool men\n";
    }

    /**
     * "Quit" was entered. Check the rest of the command to see whether we
     * really quit the game. Return quit, if this command quits the game, "quit
     * what?" otherwise.
     */
    private String quit(Command command) {
        if (command.hasSecondWord()) {
            return "Quit what?";
        } else {
            return "quit";
        }
    }
}
