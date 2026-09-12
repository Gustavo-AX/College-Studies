/*9) eliminar números repetidos do vetor. Os números repetidos devem ser substituídos por
novos números. Este procedimento deverá exibir na tela todos os elementos do vetor, antes e depois
de eliminar os números repetidos.*/

#include<stdio.h>
#include<stdlib.h>
#define TAM 50
int ordem(int V[]){
int a=V[0], substituto;
for(int i=0; i<TAM; i++){
for(int contador=0; contador<TAM;contador++){
if(V[i]<V[contador]){
substituto=V[i];
V[i]=V[contador];
V[contador]=substituto;
}
}
}
for(int i=0; i<TAM; i++){
printf("%d\n", V[i]);
}
}

int limpeza(int V[]){
int verificador=0;

for(int i=1; i<TAM; i++){
for(int a=0;a<i;a++){
if(V[i]==V[a]){
while(verificador!=i){
verificador=0;
V[i]=rand()%51;
for(int a=0; a<i; a++){
if(V[i]!=V[a])
    verificador++;
}
}
}

}
}
for(int i=0; i<TAM; i++){
printf("%d\n", V[i]);
}
}


int main(){
int V[TAM];
for(int i=0; i<TAM; i++){
	V[i]=rand()%51;
	printf("numero:%d\n", V[i]);
}
printf("\na ordem crescente e:\n");
ordem(V);
printf("sem repeticao eh:\n");
limpeza(V);
printf("\na ordem crescente e:\n");
ordem(V);
}
