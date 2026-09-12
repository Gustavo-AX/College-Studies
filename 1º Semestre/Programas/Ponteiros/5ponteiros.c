/*Implemente um programa que gera um vetor de ponteiros para os elementos do vetor de número
inteiros. Sendo que o primeiro elemento do vetor de ponteiros deve conter o endereço do maior número
do vetor de inteiros, o segundo elemento deve conter o endereço do segundo maior número do vetor de
inteiros e assim por diante. */
#include<Stdio.h>
const int tam;
int min;
int *primeiro(int *v){
int *max=&v[0];
for(int i=0; i<tam;i++){
if(v[i]>*max)
max=&v[i];
}
return max;
}

int menor(int *v){
int *max=&v[0];
int a;
for(int i=0; i<tam;i++){
if(v[i]<*max){
max=&v[i];
a=i;
}
}
return a;
}

int *maior(int *v, int *maior){
int *aux=&v[min];
for(int i=0; i<tam;i++){
if(v[i]<*maior && v[i]>*aux)
aux=&v[i];
}
return aux;
}

int main(){
printf("digite o tamanho do vetor\n");
scanf("%d", &tam);
int vetor[tam];
printf("digite os numeros do vetor\n");
for(int i=0;i<tam;i++){
scanf("%d", &vetor[i]);
}

min=menor(vetor);


int *ponteiro[tam];
ponteiro[0]=primeiro(vetor);
for(int i=1; i<tam;i++){
ponteiro[i]=maior(vetor, ponteiro[i-1]);
}

printf("o vetor normal e:\n");
for(int i=0;i<tam;i++){
printf("%d", vetor[i]);
}

printf("\no vetor em ordem decrescente e:\n");
for(int i=0;i<tam;i++){
printf("%d", *ponteiro[i]);
}
}
