/*Implemente funções que recebam a matriz 4x5 como parâmetro e
retornem: a quantidade de números com valor maior do que a média dos números da matriz*/
#include<stdio.h>
#include<stdlib.h>
int media_matriz(int matriz[4][5]){
int soma=0, contador=0;
float media;
printf("\n");
for(int m=0; m<4;m++){
for(int n=0;n<5;n++){
soma=soma+matriz[m][n];
}
}
media=((float)soma/20);
printf("\nmedia: %f\nos numeros maiores que a media sao:\n", media);

for(int m=0; m<4;m++){
for(int n=0;n<5;n++){
if(matriz[m][n]>media)
    contador++;
else
    matriz[m][n]=0;
    printf("%d\t", matriz[m][n]);
}
printf("\n");
}
return contador;
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
printf("\na quantidade de numeros com valor maior do que a media dos numeros da matriz:%d\n", media_matriz(matriz));
}
