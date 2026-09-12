/*exibir o 3o. maior elemento do vetor. Por exemplo: v={2,4,4,1,3,6,5,6} 3o. Maior= 4.*/
#include<stdio.h>
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
printf("%d\n", V[i]);
}
}

int terceiro(int V[]){
int substituto=V[0];
int i=1;
for(int contador=0; contador<15 && i<=2; contador++){
if(V[contador]>substituto){
substituto=V[contador];
i++;
}

}
return substituto;
}

int main(){
int V[15];
for(int i=0; i<15; i++){
	V[i]=rand()%21;
	printf("numero:%d\n", V[i]);
}
printf("\na ordem crescente e:\n");
ordem(V);
printf("\no terceiro maior numero e=%d\n", terceiro(V));
}
