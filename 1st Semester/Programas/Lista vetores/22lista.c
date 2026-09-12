/*Implemente funções que recebam a matriz 4x5 como parâmetro e
retornem: a soma dos números ímpares da matriz*/
#include<stdio.h>
#include<stdlib.h>
int soma_impares(int matriz[4][5]){
int soma=0;
printf("\n");
printf("os numeros impares destacados sao:\n");
for(int m=0; m<4;m++){
for(int n=0;n<5;n++){
if(matriz[m][n]%2==1)
soma=soma+matriz[m][n];
else
matriz[m][n]=0;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
return soma;
}



int main(){
int matriz[4][5];
for(int m=0;m<4;m++){
for(int n=0; n<5;n++){
matriz[m][n]=rand()%21;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
printf("\n a soma dos numeros impares equivale a:%d", soma_impares(matriz));
}
