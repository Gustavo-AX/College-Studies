package com.mycompany.zull;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class ManArqTexto {
    
    private File file;
    private Scanner entrada;
    private BufferedWriter escrever;
    private FileWriter fileWriter;
   
    public ManArqTexto() {
    }
    
    public boolean abrirArquivoGravacao(String arquivo) {
        this.file = new File(arquivo);
        
        try {
            fileWriter = new FileWriter(file);
            escrever = new BufferedWriter(fileWriter);
        } catch (IOException e) {
            System.exit(1);
        }
        return true;
    }
    
    public boolean gravarLinhaArquivo(String linha) {
        
        try {
            escrever.write(linha);
        } catch (IOException e) {
            System.exit(1);
        }
        
        return true;
    }
    
    public void fecharArquivoGravacao() {
        try {
            escrever.close();
            fileWriter.close();
        } catch (IOException e) {
            System.exit(1);
        }
    }
    
    public void abrirArquivoLeitura(String arquivo) {
        this.file = new File(arquivo);
        
        try {
            entrada = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.exit(1);
        }
    }
    
    public ArrayList<String> lerArquivo() {
        ArrayList<String> texto = new ArrayList<>();
        while (entrada.hasNext()) {
            texto.add(entrada.nextLine());
        }
        return texto;
    }
    
    public void fecharArquivoLeitura() {
        entrada = null;
    }
    
}
