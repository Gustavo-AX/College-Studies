/*Implemente funções que recebam o vetor de 15 números como parâmetro a maior diferença em valor absoluto entre elementos consecutivos do vetor;*/
#include <stdio.h>
#include<stdlib.h>

int contadora (int V[]){
int a=V[0], b, diferenca=0;
for (int i=0; i<15;i++){
//preciso de um programa que calcule a diferença entre números, par para isso preciso de achar o modulo dos numeros e subtrailos
if(V[i]-a>diferenca)
	diferenca=V[i]-a;
a=V[i];
}
return diferenca;
}



int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}
printf("\na maior diferença em valor absoluto entre elementos consecutivos do vetor e=%d\n", contadora(V));
}

