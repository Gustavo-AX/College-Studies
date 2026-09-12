/*Implemente funções que recebam o vetor de 15 números como parâmetro e retornem a quantidade de números pares do vetor;*/
#include<stdio.h>
#include<stdlib.h>

int pares(int *V){
	int contador=0;
	for(int i=0; i<15; i++){
		if(V[i]%2==0)
			contador+=1;
	}
	return contador;
}

int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}
printf("\nquantidade de pares=%d\n", pares(V));
}


