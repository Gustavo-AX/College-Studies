#include<stdio.h>
int main(){
int N;
printf("digite o tamanho do vetor\n");
scanf("%d", &N);
int X[N];
printf("digite os valores do vetor\n");
for(int i=0;i<N;i++){
scanf("%d",&X[i]);
}
int aux=X[0], posicao=0;
for(int i=0;i<N;i++){
if(X[i]<aux){
aux=X[i];
posicao=i;
}
}
printf("menor valor: %d \nposicao: %d", aux, posicao);
}
