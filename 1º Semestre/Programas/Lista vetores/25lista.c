/*Implemente funções que recebam a matriz 4x5 como parâmetro e
retornem: o segundo maior valor da matriz*/
#include<stdio.h>
#include<stdlib.h>

int segundo_maior(int matriz[4][5]){
int maior=matriz[0][0], substituto;
for(int m=0;m<4;m++){
for(int n=0; n<5; n++){
if(matriz[m][n]>maior)
maior=matriz[m][n];
}
}
printf("maior=%d\nordem crescente da matriz:\n",maior);

for(int m=0;m<4;m++){
for(int n=0; n<5; n++){
    for(int x=0;x<4;x++){
    for(int y=0; y<5; y++){
            if(matriz[m][n]<matriz[x][y]){
            substituto=matriz[m][n];
            matriz[m][n]=matriz[x][y];
            matriz[x][y]=substituto;
            }
    }
    }
}
}
for(int m=0;m<4;m++){
for(int n=0; n<5;n++){
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
int segundo_maior=matriz[0][0];
for(int m=0;m<4;m++){
for(int n=0; n<5;n++){
if(matriz[m][n]>segundo_maior && matriz[m][n]<maior)
    segundo_maior=matriz[m][n];
}
}
return segundo_maior;
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
printf("\no segundo maior numero da matriz e:%d\n", segundo_maior(matriz));
}
