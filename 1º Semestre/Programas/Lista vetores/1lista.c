/*1) Escreva um programa que armazena 15 números inteiros aleatórios em um vetor.  O vetor
deverá ser uma variável local dentro da função “main”.*/
#include<stdio.h>
#include<stdlib.h>

int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}

}