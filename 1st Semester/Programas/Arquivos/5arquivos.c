/*5) Implemente um programa que solicite um nome de arquivo ao usuário e conte a quantidade
de bytes do arquivo informado. Teste seu programa com os arquivos criados nos exercícios
anteriores.*/

#include<stdlib.h>
#include<stdio.h>

int main(){
FILE *file;
char nome_arquivo[200];
printf("digite o endereço do arquivo\n");
gets(nome_arquivo);
file=fopen(nome_arquivo,"r");

if(file==NULL){
printf("erro na abertura");
    system("pause");
    exit(1);
}

fseek(file, 0, SEEK_END);
long int bytes=ftell(file);
printf("\no tamanho do arquivo e: %d", bytes);
fclose(file);
}
