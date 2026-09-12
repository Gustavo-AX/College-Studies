#include<stdio.h>
/*“char * strchar (char *s, char ch)” que retorna o endereço da primeira
ocorrência de “ch” em “s”; caso não exista, retorna NULL (NULL é uma constante
simbólica que indica que o ponteiro não aponta para nenhuma variável). Implemente a
função principal (“main”) para testar a função strchar.*/

char *strchar(char *s, char ch){

    for(int i=0; s[i]!='\0'; i++){
        if(s[i]==ch)
            return &s[i];
    }
    return NULL;
}


int main(){
char string[100], ch;
printf("digite a string\n");
char *s=&string;
gets(s);
printf("digite a letra que deseja verificar\n");
scanf("%c", &ch);
printf("o endereço de memoria e %p", strchar(s, ch));

}
