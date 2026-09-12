/*Implemente funções que recebam o vetor de 15 números como parâmetro e retornem a soma dos números ímpares do vetor;;*/
#include<stdio.h>
#include<stdlib.h>

int soma(int *V){
int somatorio=0;
for(int i=0; i<15; i++){
if(V[i]%2!=0)
somatorio= somatorio+V[i];
}
return somatorio;
}

int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}
printf("\nsoma dos impares=%d\n", soma(V));
}
