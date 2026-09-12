/*Implemente o void eliminar(char v [ ], char ch) que elimina todas as ocorrências do
caractere“ch” no vetor de caracteres “v”. Ao eliminar um caractere, os outros elementos do vetor
devem ser movidos para esquerda. Por exemplo: v = “programacao de computadores” e ch = 'a'. Ao
final do procedimento o conteúdo de “v” deverá ser “progrmco de computadores”. Você não pode
utilizar um vetor auxiliar para implementar o procedimento.*/
#include<stdio.h>

void eliminar(char v[], char ch){
for(int i=0, a=0; v[i-1]!='\0'; i++){
if(v[i]!=ch){
    v[a]=v[i];
    a++;
}
else
v[a]=v[i+1];
}
printf("\n%s", v);
}

int main(){
char v[100], ch;
printf("digite uma senteca\n");
for(int i=0; v[i-1]!='\n';i++){
ch=getchar();
v[i]=ch;
v[i+1]='\0';
}
printf("digite a letra que deseja eliminar da setenca\n");
scanf("%c", &ch);
printf("\nteste: %c\n", ch);
eliminar(v, ch);
}
