/*Implemente funções que recebam o vetor de 15 números como parâmetro e retornem a quantidade de números com valor maior do que a média dos números do vetor;*/
#include<stdio.h>
#include<stdlib.h>

int contadora(int *V){
int media, soma=0, contador=0;
for(int i=0; i<15; i++){
soma=soma+V[i];
}
media = soma/15;
printf("media=%d", media);
for(int i=0; i<15; i++){
if(V[i]>media)
	contador=contador+=1;
}
return contador;
}


int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}
printf("\nquantidade de numeros acima da media=%d\n", contadora(V));
}