/*6) Implemente um programa que realiza a cópia de um arquivo. Teste seu programa com um
arquivo de áudio ou uma imagem.*/

#include<stdlib.h>
#include<stdio.h>

int main(){
FILE *f_origem, *f_destino;
char origem[200], dest[100];
char ch;

printf("digite o nome do arquivo de origem\n");
gets(origem);
f_origem=fopen(origem,"rb");
if(f_origem==NULL){
printf("erro na abertura");
system("pause");
exit(1);
}

printf("digite o nome do arquivo de destino\n");
gets(dest);
f_destino=fopen(dest,"wb");
if(f_destino==NULL){
printf("erro na abertura");
system("pause");
exit(1);
}


while ((ch = fgetc(f_origem)) != EOF)
fputc (ch, f_destino);

fclose(f_origem);
fclose(f_destino);
}
