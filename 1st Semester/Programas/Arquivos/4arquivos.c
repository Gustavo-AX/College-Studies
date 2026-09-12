/*4) Implemente um programa que abra o arquivo binário criado no exercício anterior e
conte quantas vezes a letra “a” aparece no nome.*/

#include<stdlib.h>
#include<stdio.h>

int main(){
FILE *file;
file=fopen("C:\\Users\\USER\\Desktop\\3lista.txt", "rb");
if(file==NULL){
    printf("erro na abertura");
    system("pause");
    exit(1);
}

char c;
int i=0;
c=fgetc(file);
while(c!=EOF){
if(c=='a')
i++;
c=fgetc(file);
}
printf("o numero de vezes que a letra 'a' aparece e: %d", i);
fclose(file);
}
