#include<stdio.h>
/*Faça um programa que solicita ao usuário dois números inteiros diferentes “n1” e “n2” e chama uma
função que calcula e retorna a soma de todos os números ímpares dentro do intervalo definidor por
[n1,...,n2]. Antes de chamar a função, o programa principal deve testar se n1 é menor do que n2.*/

int somadosimpares(int n1, int n2);

int main(){
int n, m, t;
printf("digite dois numeros referentes ao intervalo:\n");
scanf("%d %d", &n, &m);
if(n>m){
t=n;
n=m;
m=t;
}
printf("A soma dos numeros primos no intervalo e: %d", somadosimpares(n, m));
}

int somadosimpares(int n, int m){
int soma=0, impares;
for( n; n<=m ; n=n+1){
if(n%2 != 0)
    soma=soma+n;
}
return soma;
}
