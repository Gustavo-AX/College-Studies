/*3) “char *strstr (char *str1, char *str2)” que retorna o endereço de str1 em que
ocorre pela primeira vez a substring str2. Caso a substring str2 não exista em str1,
retorne NULL. Implemente o programa principal para testar a função. No programa
principal, você deve exibir o endereço do primeiro caracter de str1 e também o
endereço de str1 a partir do qual existe uma ocorrência de str2.
*/



#include<stdio.h>

char *strstr (char *str1, char *str2){
int validador=0;
for(int i=0; str1[i]!='\0';i++){
if(str1[i]==str2[0]){
validador=1;
for(int a=0;str2[a]!='\0';a++){
if(str1[a+i]!=str2[a])
validador=0;
}
if(validador==1)
return &str1[i];
}
}
return NULL;
}

int main(){
char string1[100], string2[100];
printf("digite a string\n");
fgets(string1,100,stdin);
printf("digite a string 2\n");
fgets(string2,100,stdin);
printf("o endereco da primeira ocorrencia da string2 na string 1 e: %p\n",strstr(string1,string2));
}
