#include<stdio.h>
int main(){
int retorno, posicao, numero=2, contadora=0, geoide;
printf("digite a posicao do numero primo que voce quer\n");
scanf("%d", &posicao);
for(; contadora<=posicao; ++numero){
    retorno = primo(numero);
    geoide=numero;
    if(retorno==1){
        contadora= contadora + 1;
    }
    }
        printf("o numero e %d", geoide);

}

int primo(int numero){
int contador=0, divisor=1, resto=0;
    for(divisor=1; divisor<=numero; ++divisor){
        resto = numero%divisor;
        if(resto==0){
        contador = contador + 1;
        }
        }
        if(contador==2){
        return 1;
        }
        else {
        return 0;
        }
}




