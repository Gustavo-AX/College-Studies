/*Leia um caractere maiúsculo ('S' ou 'M', indicando a operação Soma ou Média), que
deverá ser realizada com os elementos de uma matriz M[12][12]. Em seguida, calcule
e mostre a soma ou a média considerando somente aqueles elementos que estão na
área superior da matriz, conforme ilustrado abaixo (área verde). A matriz deve ser
preenchida com números aleatórios.*/
#include<stdio.h>
#include<stdlib.h>
#define M 12

int soma_media(int matriz[M][M], char letra){
int soma=0;
float media;
for(int m=0;m<5;m++){
for(int n=(m+1);n<(M-(m+1));n++){
soma=soma+matriz[m][n];
}
}
media=((float)soma/30);
if(letra=='S')
printf("\nsoma: %d", soma);
if(letra=='M')
printf("\nmedia: %.2f", media);
}



int main(){
int matriz[M][M];
char letra;
for(int m=0;m<M;m++){
for(int n=0;n<M;n++){
matriz[m][n]=rand()%6;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
printf("se deseja a soma, digite 'S', e se deseja a media, digite 'M'\n");
scanf("%c", &letra);
soma_media(matriz, letra);
}

