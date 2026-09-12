/*5) Criar um tipo abstrato de dados (struct) que represente uma pessoa, contendo nome, data de
nascimento e CPF. Crie uma variável que é um ponteiro para esta estrutura no programa principal.
Crie a função preencher que receba este ponteiro e preencha os dados da estrutura. Crie a função
exibir que receba o ponteiro para a estrutura e imprima todos os elementos. Chame as duas funções
a partir do programa principal.*/

#include<stdio.h>
#include<stdlib.h>
struct pessoa{
char nome[100];
char nascimento[11];
char cpf[15];
};

void preencher(struct pessoa *ponteiro){
printf("digite o nome\n");
fgets((*ponteiro).nome, 99, stdin);
printf("digite a data de nascimento\n");
scanf("%s", (*ponteiro).nascimento);
printf("digite o cpf\n");
scanf("%s", (*ponteiro).cpf);
}

void exibir(struct pessoa *ponteiro){
printf("\n%s", (*ponteiro).nome);
printf("%s\n", (*ponteiro).nascimento);
printf("%s\n", (*ponteiro).cpf);
}


int main(){
struct pessoa p, *ponteiro;
ponteiro=&p;
preencher(ponteiro);
exibir(ponteiro);
}
