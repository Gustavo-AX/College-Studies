/*11) Implemente a função int compara (int vetor1 [ ], int vetor2 [ ]) que retorna 1 caso os
vetores sejam iguais e 0 caso contrário. A quantidade de elementos em cada vetor pode ser
diferente. Se julgar necessário, passe outros parâmetros para a função.*/

#include<stdio.h>
#include<stdlib.h>
const int TAM1;
const int TAM2;

int compara(int vetor1[], int vetor2[], int TAM1, int TAM2){
int validador=1;
if(TAM1!=TAM2)
return 0;
else{
for(int i=0;i<TAM1 && validador!=0;i++){
if(vetor1[i]!=vetor2[i])
validador=0;
}
if (validador == 0)
return 0;
else
return 1;
}
}


int main(void){
int verificador;
printf("digite o tamanho do vetor 1\n");
scanf("%d", &TAM1);
printf("digite o tamanho do vetor 2\n");
scanf("%d", &TAM2);

int vetor1[TAM1], vetor2[TAM2];
printf("digite os numeros do vetor 1\n");
for(int i=0;i<TAM1;i++){
scanf("%d", &vetor1[i]);
}
printf("digite os numero do vetor 2\n");
for(int i=0;i<TAM2;i++){
scanf("%d", &vetor2[i]);
}
verificador=compara(vetor1, vetor2, TAM1,TAM2);
if(verificador==1)
printf("sao iguais");
else
printf("sao diferentes");
}
