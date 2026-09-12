/*Implemente o procedimento “void concatenar (char s1[], char s2[])” que copia o string
s2 a partir do final de s1. Exemplo: s1 = “abc”, s2= “def”, após o procedimento concatenar s1 terá
o conteúdo s1= “abcdef”.*/
#include<stdio.h>

int concatear(char S1[], char S2[]){
int contador=0;
for(int i=0; S1[i]!='\0'; i++){
contador++;
}
for(int i=0; S2[i-1]!='\0'; i++){
S1[contador+i]=S2[i];
}
return S1;
}

int main(){
char S1[100], S2[100];
printf("digite a primeira palavra\n");
scanf("%s", S1);
printf("digite a segunda palavra\n");
scanf("%s", S2);
printf("as palavras unidas sao:\n%s", concatear(S1, S2));
}
