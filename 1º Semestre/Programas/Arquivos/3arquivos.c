/*3) Implemente um programa que grave um string (seu nome, por exemplo) em um arquivo
binário.*/

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
file=fopen("C:\\Users\\USER\\Desktop\\3lista.txt", "wb");
if(file==NULL){
    printf("erro na abertura");
    system("pause");
    exit(1);
}

char nome[100];
printf("digite o seu nome\n");
fgets(nome, 100, stdin);
fwrite(nome, sizeof(char), contador_letra(nome), file);
fclose(file);
}
