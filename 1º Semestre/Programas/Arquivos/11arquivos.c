/*11) Uma empresa permite que seus funcionários façam chamadas internacionais a partir de seus
ramais, mas mantém um registro dessas ligações no arquivo “ci.txt”. Cada linha do arquivo
contém a matrícula de um funcionário (inteiro), o número de chamadas internacionais
realizadas e a duração em minutos de cada uma das ligações. Exemplo:
1124 2  3.4 2.2
3095 0
4127 1  9.5
9440 3  7.4 15.2 30.8

Escreva um programa em C que leia o arquivo “ci.txt” e gere o arquivo “totais.txt”. O
arquivo “totais.txt” deverá conter, para cada funcionário que efetuou chamadas
internacionais, uma linha com seu número de matrícula e a duração total de suas chamadas.
A última linha do arquivo deve conter a duração total das chamadas internacionais.
Exemplo:
1124 5.6
4127 9.5
9440 53.4
68.5 (aqui é a soma de todas)
*/
#include<stdio.h>

int main(){
FILE *file, *total;
file=fopen("ci.txt", "r");
if(file==NULL){
    printf("nao deu");
    return 1;
}
total=fopen("totais.txt", "w");
if(total==NULL){
    printf("nao deu");
    return 1;
}

int matricula, x;
float aux=0, duracao, totalmente=0;

while(fscanf(file,"%d %i", &matricula,&x)!=EOF){
if(x>0){
    for(int i=0;i<x;i++){
    fscanf(file,"%f", &duracao);
    aux=aux+duracao;
    }

fprintf(total,"%i %.1f\n", matricula, aux);
totalmente=totalmente+aux;
aux=0;
}
}
fprintf(total, "%.1f", totalmente);
fclose(total);
fclose(file);
}
