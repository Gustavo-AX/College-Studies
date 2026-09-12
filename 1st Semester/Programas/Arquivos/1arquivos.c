/*1) Implemente um programa que grave um string (seu nome, por exemplo) em um arquivo
texto.*/

#include<stdlib.h>
#include<stdio.h>

int main(){
FILE *f;
f = fopen("C:\\Users\\USER\\Desktop\\teste.txt", "w");
if(f==NULL){
printf("\nerro na abertura\n");
system("pause");
exit(1);
}
char nome[100];
int validador;
printf("digite o seu nome\n");
fgets(nome, 100, stdin);
validador=fputs(nome, f);
if(validador==EOF)
    printf("\nfalha ao gravar\n");
fclose(f);
}
