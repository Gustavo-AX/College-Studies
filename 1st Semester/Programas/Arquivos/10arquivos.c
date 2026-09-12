/*10) Escreva um programa para ler o conteúdo de um arquivo contendo as notas obtidas pelos
alunos de uma turma. O programa deve exibir na tela o valor da nota mínima, valor da nota
máxima e o total de alunos aprovados e reprovados (considere que o aluno é aprovado se a
nota for maior ou igual a 60.0). O formato do arquivo pode ser texto ou binário e seu
conteúdo é o seguinte:
75
84
91
40
57
43
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *file;
char nome_arquivo[100];
printf("digite o nome do arquivo com as notas\n");
gets(nome_arquivo);
file=fopen(nome_arquivo,"r");
if(file==NULL){
    printf("não foi possivel abrir o arquivo\n");
    return 1;
}

int v[100], a=0;
while(fscanf(file,"%d\n",&v[a])!=EOF){
    a++;
}

int aux_max=v[0], aux_min=v[0], contador=0;
for(int i=0;i<a;i++){
    if(v[i]>aux_max)
        aux_max=v[i];
    if(v[i]<aux_min)
        aux_min=v[i];
    if(v[i]>=60)
        contador++;
}
printf("a nota maxima e: %d, a nota minima e: %d, o numero de alunos aprovados e: %d e reprovador e: %d", aux_max, aux_min, contador, a-contador);


}


