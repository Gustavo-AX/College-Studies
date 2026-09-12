/*9) Implemente um programa que apaga todas as ocorrências de uma certa palavra em um
arquivo texto. Sugestão: copie o conteúdo do arquivo texto para um arquivo auxiliar, com
exceção da palavra que se deseja excluir. Ao final, apague o arquivo texto original e altere o
nome do auxiliar (use as funções system(“del arquivo.txt”); system(“copy
auxiliar.txt arquivo.txt”); system(“del auxiliar.txt”)).*/
#include<stdio.h>

int contador_letra(char string[]){
int i=0;
while(string[i]!='\0')
    i++;
return i;
}

int main(){
FILE *file, *f_aux;
char arquivo[100];
printf("digite o nome do arquivo, e sua extensao\n");
gets(arquivo);
file=fopen(arquivo, "r");

f_aux=fopen("terere.txt", "w");

char palavra[50];
printf("digite uma palavra\n");
scanf("%s", &palavra);

char c;
int aux=contador_letra(palavra);
int i=0;
printf("\nnumero de letras da palavra:%d\n", aux);

while((c=fgetc(file))!= EOF){

fputc(c,f_aux);

if(c==palavra[i]);
i++;

if(i==aux){
fseek(f_aux, -(aux+1), SEEK_CUR);
i=0;
}

if(palavra[i]!=c)
i=0;

}

}

