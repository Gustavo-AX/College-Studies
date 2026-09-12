/*7) colocar em ordem crescente os elementos do vetor. No programa principal, exiba o vetor antes e depois de ordena-lo.*/
#include <stdio.h>
#include<stdlib.h>

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
for(int i=0; i<15; i++){
printf("\n%d\n", V[i]);
}
}


int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}
ordem(V);
}