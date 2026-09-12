#include <stdio.h>
#include<stdlib.h>
/*Implelmente a função float max(float v [ ], int n) que retorna o maior número entre os n
primeiros elementos de um vetor.*/

const int TAM;
const int n;

int maior(int V[], int n){
int aux=V[0];
for(int i=1;i<n;i++){
if(V[i]>aux)
aux=V[i];
}
printf ("o maior numero eh:%d", aux);
}



int main(void){
printf("digite o tamanho do vetor\n");
scanf("%d", &TAM);
printf("tamanho:%d\n", TAM);
printf("digite o numero referente ao intervalo a ser analisado, em busca do maior numero nele.\n");
scanf("%d", &n);
int V[TAM];
printf("numero:\n");

for(int i=0; i<TAM; i++){
V[i]=rand()%TAM;

printf("%d\n", V[i]);
}
maior(V, n);
}
