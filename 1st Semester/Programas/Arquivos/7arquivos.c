/*7) Implemente um programa que compara o tamanho de 2 arquivos e informa qual possui a
maior quantidade de bytes.*/


#include<stdlib.h>
#include<stdio.h>

int main(){
FILE *file1, *file2;
char arquivo1[200], arquivo2[100];

printf("digite o nome do arquivo 1\n");
gets(arquivo1);
file1=fopen(arquivo1,"rb");
if(file1==NULL){
printf("erro na abertura");
system("pause");
exit(1);
}

printf("digite o nome do arquivo 2\n");
gets(arquivo2);
file2=fopen(arquivo2,"rb");
if(file2==NULL){
printf("erro na abertura");
system("pause");
exit(1);

}
fseek(file1, 0, SEEK_END);
long int bytes1=ftell(file1);
printf("\no tamanho do arquivo1 e: %d", bytes1);

fseek(file2, 0, SEEK_END);
long int bytes2=ftell(file2);
printf("\no tamanho do arquivo2 e: %d", bytes2);

if(bytes1>bytes2)
    printf("\no arquivo 1 e maior que o 2");
else
    printf("\no arquivo 2 e maior que 1");
}
