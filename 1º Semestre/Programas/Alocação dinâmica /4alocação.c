/*4) Implemente um programa que preenche aleatoriamente dois vetores Q e R com 12 e 20
elementos inteiros (valores repetidos ou não) respectivamente. Implemente um procedimento que
recebe os vetores Q, R e um terceiro vetor W. O procedimento deverá preencher o vetor W com a
interseção de Q e R. Além disto, W não poderá conter elementos repetidos. Exiba o conteúdo do
vetor W no programa principal. Utilize a função malloc para os vetores Q e R. Utilize a função
realloc toda vez que um elemento for inserido no vetor W. Não utilize variáveis globais.*/

#include<Stdio.h>
#include<stdlib.h>

int *preencher(int *v, int n){
v = (int*) malloc (n*sizeof(int));
for(int i=0;i<n;i++){
v[i]=rand()%21;
printf("%d ", v[i]);
}
return v;
}

int main(){
int *Q, *R;
printf("vetor Q:\n");
Q=preencher(Q, 12);
printf("\nvetor R:\n");
R=preencher(R, 20);
printf("\nvetor W:\n");
int *W;
int n=0, validador=1;
W=(int*)malloc(1 * sizeof(int));

for(int i=0; i<12;i++){
for(int a=0; a<20;a++){


if(Q[i]==R[a]){
for(int x=0;x<n;x++){
if(Q[i]==W[x])
validador=0;
}
if(validador==1){
W=(int*) realloc (W, (n+1)*sizeof(int));
W[n]=Q[i];
n++;
}
validador=1;
}
}
}
for(int i=0; i<n;i++){
printf("%d ", W[i]);
}
free(Q);
free(R);
free(W);
}



