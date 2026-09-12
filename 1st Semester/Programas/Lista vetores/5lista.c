/*Implemente funções que recebam o vetor de 15 números como parâmetro e retornem o maior valor do vetor;*/

#include <stdio.h>
#include<stdlib.h>

int contadora(int *V){
int substituto=V[0];
for(int i=0; i<15; i++){
if(V[i]>substituto)	
substituto=V[i];
}
return substituto;
}


int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}
printf("\no maior numero e=%d\n", contadora(V));
}
