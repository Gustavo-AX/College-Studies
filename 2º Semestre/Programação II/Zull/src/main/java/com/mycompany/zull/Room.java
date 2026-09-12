package com.mycompany.zull;

import java.util.ArrayList;

/*
 * Class Room - a room in an adventure game.
 *
 * This class is the main class of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 *
 * A "Room" represents one location in the scenery of the game.  It is 
 * connected to other rooms via exits.  The exits are labelled north, 
 * east, south, west.  For each direction, the room stores a reference
 * to the neighboring room, or null if there is no exit in that direction.
 * 
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */


class Room {
    
    public String description;
    private ArrayList<Interativo> interativos;
    //usei aqui um array definido por que o número de direçoes é definido, também seria possível usar 
    //um HashMap, porém não agregaria mt ao programa
    
    //rooms[0]=north,rooms[1]=east,rooms[2]=south, rooms[3]=west,rooms[4]=up, rooms[5]=down
    public Room[] rooms = new Room[6];
   

    /**
     * Create a room described "description". Initially, it has no exits.
     * "description" is something like "a kitchen" or "an open court yard".
     */
    
    public Room(String description) {
        this.description = description;
        interativos=new ArrayList<>();
    }

    /**
     * Define the exits of this room. Every direction either leads to another
     * room or is null (no exit there).
     */
    public void setExits(Room north, Room east, Room south, Room west, Room up, Room down) {
        if (north != null) {
            rooms[0]= north;
        }
        if (east != null) {
            rooms[1] = east;
        }
        if (south != null) {
            rooms[2] = south;
        }
        if (west != null) {
            rooms[3] = west;
        }
        if (up != null){
            rooms[4] = up;
        }
        if (down != null){
            rooms[5] = down;
        }
    }
    
    public void addInterativos(Interativo interativo){
        this.interativos.add(interativo);
    }
    
    public ArrayList<Interativo> getInterativos(){
        return this.interativos;
    }

    /**
     * Return the description of the room (the one that was defined in the
     * constructor).
     */
    public String getDescription() {
        return description;
    }

}
