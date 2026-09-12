/*Implemente funções que recebam a matriz 4x5 como parâmetro e
retornem: o maior valor da matriz*/
#include<stdio.h>
#include<stdlib.h>

int maior(int matriz[4][5]){
int substituto=matriz[0][0];
for(int m=0;m<4;m++){
for(int n=0; n<5; n++){
if(matriz[m][n]>substituto)
substituto=matriz[m][n];
}
}
return substituto;
}

int main(){
int matriz[4][5];
for(int m=0;m<4;m++){
for(int n=0; n<5;n++){
matriz[m][n]=rand()%51;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
printf("\n o maior numero da matriz e:%d", maior(matriz));
}
