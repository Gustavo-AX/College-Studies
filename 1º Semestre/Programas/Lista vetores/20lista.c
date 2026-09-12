/*Escreva um programa que armazena 20 valores aleatórios em uma matriz 4x5. A matriz
deverá ser uma variável local dentro da função “main”.*/
#include<stdio.h>
#include<stdlib.h>

int main(){
int matriz[4][5];
int a=0;
for(int m=0; m<4;m++){
for(int n=0; n<5; n++){
matriz[m][n]=rand()%21;
printf(" %d", matriz[m][n]);
}
printf("\n");
}
}
