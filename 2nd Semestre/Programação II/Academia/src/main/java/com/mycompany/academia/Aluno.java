package com.mycompany.academia;

public class Aluno {
private String nome;
private String sexo;
private int idade;
private double peso;
private double altura;
private String telContato;

public void setNome(String nome){
this.nome=nome;
}
public void setSexo(String sexo){
this.sexo=sexo;
}
public void setIdade(int idade){
this.idade=idade;
}
public void setPeso(double peso){
this.peso=peso;
}
public void setAltura(double altura){
this.altura=altura;
}
public void setTelContato(String telContato){
this.telContato=telContato;
}

public String getNome(){
return this.nome;
}
public String getSexo(){
return this.sexo;
}
public int getIdade(){
return this.idade;
}
public double getPeso(){
return this.peso;
}
public double getAltura(){
return this.altura;
}
public String getTelContato(){
return this.telContato;
} 
}
