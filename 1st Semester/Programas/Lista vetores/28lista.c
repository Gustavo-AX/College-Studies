/*Uma empresa tem registrado em uma tabela os consumos mensais de energia elétrica dos
anos de 2003 até 2010. Cada linha representa um ano e cada coluna representa um mês.
Considerando esses dados, faça um algoritmo para processar a tabela e produzir as seguintes
informações:
1. Consumo médio em cada um dos meses;
2. Mês/ano em que houve o maior gasto com energia.*/

#include<stdio.h>
#include<stdlib.h>

const int x=8;
const int y=12;

int consumo(int matriz[x][y]){
int soma=0, maior;
float media;
printf("\n");
for(int m=0; m<x;m++){
for(int n=0;n<y;n++){
soma=soma+matriz[m][n];
}
}
media=((float)soma/(x*y));
printf("\na media de cada um dos meses e: %.2f:\n", media);
maior=matriz[0][0];
int a, b;
for(int m=0; m<x;m++){
for(int n=0;n<y;n++){
        if(matriz[m][n]>=maior){
        maior=matriz[m][n];
        a=m;
        b=n;
        }
}
}
printf("o mes com o maior gasto foi o mes %d do ano %d", (b+1),(2003+a));
}




int main(){
int matriz[x][y];
char letra;
for(int m=0;m<x;m++){
for(int n=0; n<y;n++){
matriz[m][n]=rand()%1001;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
consumo(matriz);
}
