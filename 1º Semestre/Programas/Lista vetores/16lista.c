/*Implemente a função int compara (char string1 [ ], char string2 [ ]) que retorna 1 caso
as strings sejam iguais e 0 caso contrário.*/
#include<stdio.h>

int compara(char string1[], char string2[]){
int i=0;
while(string1[i]==string2[i]&&string1[i]!='\0'&&string2[i]!='\0'){
    i++;
}
if(string1[i]=='\0' && string2[i]=='\0'){
return 1;
}
else
    return 0;
}

int main(){
char string1[100], string2[100], letra='x';
printf("digite a primeira setenca\n");
for(int i=0; string1[i-1]!='\n'; i++){
    letra=getchar();
    string1[i]=letra;
    string1[i+1]='\0';
}
printf("digite a segunda setenca\n");
for(int i=0; string2[i-1]!='\n'; i++){
    letra=getchar();
    string2[i]=letra;
    string2[i+1]='\0';
}

if(compara(string1, string2))
printf("sao iguais");
else
printf("nao sao iguais");
}
