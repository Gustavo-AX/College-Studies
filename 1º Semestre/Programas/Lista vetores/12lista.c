/*12) Implemente uma função que conta e retorna a quantidade de caracteres existente em um
string passado como parâmetro.*/
#include<stdio.h>
#include<stdlib.h>

int num(char string[]){
int contador=0;
while(string[contador]!='\0'){
contador++;
}
return contador;
}

int main(void){
char string[100];
printf("digite uma palavra\n");
scanf("%s", string);
printf("o numero de caracteres da string %s e: %d", string, num(string));
}

