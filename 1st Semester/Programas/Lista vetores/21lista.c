/*Implemente funções que recebam a matriz 4x5 como parâmetro e
retornem: a quantidade de números pares da matriz;*/
#include<stdio.h>
#include<stdlib.h>
int pares(int matriz[4][5]){
int contador=0;
printf("\n os numeros pares destacados sao:\n");
for(int m=0; m<4;m++){
for(int n=0; n<5;n++){
if(matriz[m][n]%2==0){
contador++;
}
else
matriz[m][n]=0;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
printf("\na quantidade de numeros pares e:%d", contador);
}


int main(){
int matriz[4][5];
int a=0;
for(int m=0; m<4;m++){
for(int n=0; n<5; n++){
matriz[m][n]=rand()%21;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
pares(matriz);
}
