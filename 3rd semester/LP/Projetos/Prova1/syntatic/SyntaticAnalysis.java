package syntatic;

import java.util.List;

import lexical.LexicalAnalysis;
import lexical.Token;

import static lexical.Token.Type.UNEXPECTED_EOF;
import static lexical.Token.Type.INVALID_TOKEN;
import static lexical.Token.Type.END_OF_FILE;

import static lexical.Token.Type.DOT;
import static lexical.Token.Type.NOT;
import static lexical.Token.Type.LOWER_THAN;
import static lexical.Token.Type.GREATER_THAN;
import static lexical.Token.Type.OPEN_PAR;
import static lexical.Token.Type.CLOSE_PAR;
import static lexical.Token.Type.DEFINE;
import static lexical.Token.Type.UNDEF;
import static lexical.Token.Type.ERROR;

import static lexical.Token.Type.INCLUDE;
import static lexical.Token.Type.IFDEF;
import static lexical.Token.Type.IFNDEF;
import static lexical.Token.Type.IF;
import static lexical.Token.Type.ELIF;
import static lexical.Token.Type.ELSE;
import static lexical.Token.Type.ENDIF;
import static lexical.Token.Type.NAME;
import static lexical.Token.Type.TEXT;
import static lexical.Token.Type.NUMBER;

public class SyntaticAnalysis {

    private LexicalAnalysis lex;
    private Token previous;
    private Token current;
    private Token next;

    public SyntaticAnalysis(LexicalAnalysis lex) {
        this.lex = lex;
        this.previous = null;
        this.current = lex.nextToken();
        this.next = lex.nextToken();
        System.out.println("bbbbbbbbbbbbbbbbbb");
    }

    public void process() {
        procCode();
    }

    private void advance() {
        System.out.println("Found " + current);
        previous = current;
        current = next;
        next = lex.nextToken();
    }

    private void eat(Token.Type type) {
        if (type == current.type) {
            advance();
        } else {
            // System.out.println("Expected (..., " + type + ", ..., ...), found " +
            // current);
            reportError();
        }
    }

    private boolean check(Token.Type... types) {
        for (Token.Type type : types) {
            if (current.type == type)
                return true;
        }

        return false;
    }

    /*private boolean checkNext(Token.Type... types) {
        for (Token.Type type : types) {
            if (next.type == type)
                return true;
        }

        return false;
    }*/

    private boolean match(Token.Type... types) {
        if (check(types)) {
            advance();
            return true;
        } else {
            return false;
        }
    }

    private void reportError() {
        String reason;
        switch (current.type) {
            case INVALID_TOKEN:
                reason = String.format("Lexema inválido [%s]", current.lexeme);
                break;
            case UNEXPECTED_EOF:
            case END_OF_FILE:
                reason = "Fim de arquivo inesperado";
                break;
            default:
                reason = String.format("Lexema não esperado [%s]", current.lexeme);
                break;
        }

        throw new SyntaticException(current.line, reason);
    }

    // <code> ::= {<macros>}
    private void procCode() {
        //int line = current.line;
        while (check(DEFINE, IF, NOT, OPEN_PAR, TEXT, NAME)) {
            procMacros();
        }
    }

    // <macros> ::= #define|#undef|#error|#include|#ifdef|#ifndef|#if
    private void procMacros() {
        //int line = current.line;
        if (check(DEFINE)) {
            procDefine();
        } else if (check(UNDEF)) {
            //procUndef();
        } else if (check(ERROR)) {
            //procError();
        } else if (check(INCLUDE)) {
            //procInclude();
        } else if (check(IFDEF)) {
            //procIfdef();
        } else if (check(IFNDEF)) {
            //procIfndef();
        } else if (check(IF)) {
            //procIf();
        }
    }

    // <#define> ::= #define <name> [ <expr> ]
    private void procDefine() {
        eat(DEFINE);
        eat(NAME);
        if(match(TEXT,NUMBER)){
            if(previous.type == TEXT)
                eat(TEXT);
            else
                eat(NUMBER);
        }

    }
    // <#undef> ::= #undef <name>
    // <#error> ::= #error <expr>
    // <#include> ::= #include ( <expr> | ('<' <name> '>'))
    // <#ifdef> ::= #ifdef <name> <macros> [#elif(s) | #else] #endif
    // <#ifndef> ::= #ifndef <name> <macros> [#elif(s) | #else] #endif
    // <#if> ::= #if [!] #defined <name> <macros> [ #elif(s) | #else] #endif
    // <#elif> ::= [!] #defined <name> <macro> [#elif(s) | #else]
    // <#else> ::= <macro>

}
