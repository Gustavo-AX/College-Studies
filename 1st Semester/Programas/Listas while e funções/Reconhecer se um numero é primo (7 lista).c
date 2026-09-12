#include<stdio.h>
int main(){
int numero, contador=0, divisor=1, resto=0;
char letra;
letra = 'X';

while(letra != 'F'){
    printf("\ndigite um numero\n");
    scanf("%d", &numero);

    for(divisor=1; divisor<=numero; ++divisor){
        resto = numero%divisor;
        if(resto==0){
        contador = contador + 1;
        }
        }
        if(contador==2){
            printf("o numero e primo\n");
        }
        else {
        printf("o numero nao e primo\n");

        }
        divisor=1;
        contador=0;
        resto=0;
        printf("\n Voce deseja continuar? se sim, pressione 'enter', se nao, digite 'F'.\n");
        letra = getche();
        }
return 0;
}




