/*4) “void calc(int * v, int num, int * xmin, int * xmax)” que coloca nas posições de
memórias apontadas por “xmin” e “xmax” o menor e o maior valor (respectivamente)
existentes nos “num” primeiros inteiros do vetor “v”.
*/

#include<stdio.h>

const int tam;

void calc(int * v, int num, int * xmin, int * xmax){
*xmax=v[0], *xmin=v[0];
for(int i=0; i<num;i++){
if(v[i]>(*xmax))
*xmax=v[i];
if(v[i]<(*xmin))
*xmin=v[i];
}
}




int main(){
int max, min;
int num, *xmin, *xmax;
xmax=&max;
xmin=&min;
printf("digite o tamanho do vetor\n");
scanf("%d", &tam);
int vetor[tam];
printf("digite os valores do vetor\n");
for(int i=0;i<tam;i++){
scanf("%d", &vetor[i]);
}
printf("digite os n primeiros numeros que deseja analisar\n");
scanf("%d", &num);
calc(vetor, num, xmin, xmax);
printf("o menor valor e %d, e o maior valor e %d", *xmin, *xmax);
}
