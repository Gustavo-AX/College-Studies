/*Você deve ler 15 valores e colocá-los em 2 vetores conforme estes valores foram pares ou ímpares.
Só que o tamanho de cada um dos dois vetores é de 5 posições. Então, cada vez que um dos dois
vetores encher, você deverá imprimir todo o vetor e utilizá-lo novamente para os próximos números que
forem lidos. Terminada a leitura, deve-se imprimir o conteúdo que restou em cada um dos dois vetores,
imprimindo primeiro os valores do vetor impar. Cada vetor pode ser preenchido tantas vezes forem
necessárias.*/
#include<stdio.h>

int par_impar(int v[]){
int v_par[5], v_impar[5], a=0, b=0;

for(int i=0; i<15;i++){

if(v[i]%2==0){
v_par[a]=v[i];
a++;
if(a==5){
for(int x=0;x<5;x++){
printf("par[%d] = %d\n", x, v_par[x]);
}
a=0;
}
}

else{
v_impar[b]=v[i];
b++;
if(b==5){
for(int x=0;x<5;x++){
printf("impar[%d] = %d\n", x, v_impar[x]);
}
b=0;
}
}
if(i==14){
for(int x=0; x!=b;x++){
printf("impar[%d] = %d\n", x, v_impar[x]);
}
for(int x=0; x!=a;x++){
printf("par[%d] = %d\n", x, v_par[x]);
}
}
}
}




int main(){
int v[15], aux;
printf("digite os 15 valores:\n");
for(int i=0; i<15;i++){
scanf("%d", &v[i]);
}
par_impar(v);
}
