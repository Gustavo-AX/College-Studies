/*3) Um dia o Prof. Humberto José Roberto fez o seguinte questionamento: Se o zero a esquerda de
um número não tem valor algum, por que teria em outras posições de um número? Analisando da
seguinte forma, ele pede sua ajuda para, ao somar dois valores inteiros, que o resultado seja exibido
segundo o raciocínio dele, ou seja, sem os Zeros. Por exemplo, ao somar 15 + 5, o resultado seria
20, mas com esta nova ideia, o novo resultado seria 2, e, ao somar 99 + 6, o resultado seria 105, mas
com esta nova ideia, o novo resultado seria 15.
Escreva um programa que, dado dois números inteiros, sem o algarismo zero, some os mesmos e,
caso o resultado tenha algum algarismo zero, que os retire antes de exibir.
Entrada Resultado
7 + 8 = 15
15 + 5 = 2
99 + 6 = 15
*/
#include<stdio.h>
int potencia(int X, int expoente){
int contador=1,resultado=1;
while(contador<=expoente){
resultado=resultado*X;
contador=contador+1;
}
return resultado;
}

int funcao(int A, int B){
int soma=0, expoente=-1, X, somatorio=0;
soma=A+B;
        while(soma>=1){
        if(soma%10==0)
        X=0;
        else{
        X = soma%10;
        expoente = expoente+1;
        }
        soma/=10;
        X=X * potencia(10,expoente);
        somatorio=somatorio+X;
}
printf("%d + %d = %d", A,B, somatorio);
}

int main(){
int A,B;
char letra;
letra='X';
while(letra!='F'){
printf("\ndigite dois numeros, que não contenham o numero '0' para serem somados\n");
scanf("%d %d", &A, &B);
funcao(A,B);
printf("\n\ndeseja continuar? Se sim, tecle 'enter', se não, tecle 'F'\n");
letra=getche();
}
}

