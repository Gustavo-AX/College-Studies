#include<stdio.h>
int somaprimos(int posicao);
int primo(int contadora);

int main(){
int posicao;
printf("digite o numero referente a posicao do ultimo numero primo a ser somado:\n");
scanf("%d", &posicao);
printf(" a soma dos primos e: %d", somaprimos(posicao));
}

int somaprimos(int posicao){
int soma=0, contadora=2, verificadordeprimo, master=1;
for( contadora=2; master<=posicao; ++contadora){
verificadordeprimo=primo(contadora);
if(verificadordeprimo==1){
    soma=soma+contadora;
    master=master+1;
}
}

return soma;
}

int primo(int contadora){
int contador=0, divisor=1, resto=0;
    for(divisor=1; divisor<=contadora; ++divisor){
        resto = contadora%divisor;
        if(resto==0){
        contador = contador + 1;
        }
        }
        if(contador==2)
        return 1;
        else
        return 0;
}
