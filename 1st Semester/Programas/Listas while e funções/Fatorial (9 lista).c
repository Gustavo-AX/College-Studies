/*Implemente uma função que recebe um número inteiro como parâmetro e retorna o fatorial desse
número. Se o número for menor do que zero, então a função deve retornar o valor -1. Implemente o
programa principal para testar a função. Se o valor de retorno da função for “-1”, o programa
principal deve informar que o número digitado está incorreto.*/
#include<stdio.h>
int fatorial(int numero);

int main(){
int numero;
char cod;
cod='P';
while (cod!='F'){
    if(cod=='C' || cod=='P'){
        printf("\ndigite o numero do qual deseja obter o fatorial\n");
        scanf("%d", &numero);
        printf("o fatorial desse numero e: %d", fatorial(numero));
        printf("\nSe quiser sair, digite F, se nao, tecle C\n");
        cod=getche('F');
    }
    else{
        printf("\nComando nao reconhecido.\nSe quiser sair, digite F, se nao, tecle C\n ");
        cod=getche('F');
    }
}
}

int fatorial(int numero){
int contador=1, somatorio=0, multiplicador=1;
for( ; contador<=numero ;contador++){
somatorio=contador*multiplicador;
multiplicador=somatorio;
}
return somatorio;
}
