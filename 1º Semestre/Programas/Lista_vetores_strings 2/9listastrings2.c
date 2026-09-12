#include<stdio.h>
const int N;
int diferentes(int vetor[]){
int contador=0;
for(int i=0; vetor<N; i++){
if(vetor[i]==vetor[i-1]){
    while(vetor[i]!=vetor[i-1]){
    i++;
    contador++;
}
printf("\no numero %d apareceu %d vezes", vetor[i], contador);
contador=0;
}
else
    printf("%d", vetor[i]);
}
}


int ordem(int V[]){
int a=V[0], substituto;

for(int i=0; i<15; i++){
for(int contador=0; contador<15;contador++){
if(V[i]<V[contador]){
substituto=V[i];
V[i]=V[contador];
V[contador]=substituto;
}
}

}
return V;
}

int main(){
char X[2000];
printf("digite o numero de numeros a serem analisadas\n");
scanf("%d", &N);
printf("digite as numeros, entre 1 e 2000\n");
for(int i=0;i<N;i++){
scanf("%d", X[i]);
}
ordem(X);
diferentes(X);
}

