/*Implemente o procedimento void imprime_sobrenome (char nome_completo[ ]) que
recebe o nome completo de uma pessoa e imprime o último nome. Por exemplo, para o nome
completo “Jose Maria da Silva”, o programa deve exibir: “Silva”.*/
#include<stdio.h>
void imprime_sobrenome(char nome_completo[]){
int n=0;
char last_name[100];
for(int i=0; nome_completo[i]!='\0'; i++){
if(nome_completo[i]==' ')
n=i;
}
for(int i=0; nome_completo[n+i]!='\0'; i++){
last_name[i]=nome_completo[n+i];
last_name[i+1]='\0';
}
printf("\no sobrenome e: %s",last_name);
}

int main(){
char nome_completo[100], letra;
printf("digite seu nome completo\n");
for(int i=0; nome_completo[i-1]!='\n'; i++){
    letra=getchar();
    nome_completo[i]=letra;
    nome_completo[i+1]='\0';
}
printf("o nome e: %s", nome_completo);
imprime_sobrenome(nome_completo);
}
