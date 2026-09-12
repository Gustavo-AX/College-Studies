package com.mycompany.zull;

public class InvalidCommandException extends Exception{
    private final String message;

    public InvalidCommandException(String message) {
        super(message);
        this.message = message;
    }
   
    @Override
    public String toString() {
        return message;
    }

}
