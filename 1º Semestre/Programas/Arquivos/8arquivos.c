/*8) Implemente um programa que conta quantas vezes uma certa palavra aparece em um
arquivo texto.*/

#include<stdlib.h>
#include<stdio.h>

int contador_letra(char string[]){
int i=0;
while(string[i]!='\0')
    i++;
return i;
}


int main(){
FILE *file;
char nome_arquivo[200];
printf("digite o endereço do arquivo\n");
gets(nome_arquivo);
file=fopen(nome_arquivo,"r");

char palavra[10];
printf("digite a palavra\n");
gets(palavra);
char c;
printf("palavra= %s", palavra);

int aux=contador_letra(palavra);
int contador=0, i=0;
printf("\naux:%d", aux);

while((c=fgetc(file))!= EOF){
if(c==palavra[i]);
i++;


if(i==aux){
contador++;
i=0;
}

if(palavra[i]!=c)
i=0;

printf("%c", c);
}
printf("\no numero de vezes que essa palavra apareceu no texto e: %d", contador);



}
