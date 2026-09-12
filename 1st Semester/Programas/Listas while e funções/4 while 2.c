/*4) Escreva um programa que leia um valor inteiro N (1 < N < 1000). Este N é a quantidade de
linhas de saída que serão apresentadas na execução do programa, conforme o exemplo abaixo:
Entrada Resultado
5
1 1 1
2 4 8
3 9 27
4 16 64
5 25 125
*/
#include<stdio.h>
int potencia(int numero, int expoente){
int contador=1,resultado=1;
while(contador<=expoente){
resultado=resultado*numero;
contador++;
}
return resultado;
}

int main(){
int numero, contador=1, contador2=1;
char letra;
letra='X';
while(letra!='F'){
printf("\ndigite um numero que seja maior que 1 e menor que 1000\n");
sanf("%d", &numero);

if(numero>1 && numero<1000){
for(contador=1; contador<=numero; contador++){
while(contador2<=3){
printf("  %d", potencia(contador,contador2));
contador2+=1;
}
contador2=1;
printf("\n");
}
}
else
    printf("numero invalido\n");
printf("deseja continuar? se sim, aperte qualquer tecla, se n, aperte F\n");
letra=getche();
}
}

