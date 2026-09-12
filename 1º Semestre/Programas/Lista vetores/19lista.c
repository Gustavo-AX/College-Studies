/*19) Implemente um procedimento que coloca em ordem crescente os caracteres de um string
“s” passado como parâmetro.*/
#include<stdio.h>
int ordem(char string[]){
char substituto;
for(int i=0; string[i]!='\0'; i++){
    for(int contador=0; string[contador]!='\0'; contador++){
        if(string[i]<string[contador]){
        substituto=string[i];
        string[i]=string[contador];
        string[contador]=substituto;
}
}
}
printf("\n%s", string);
}

int main(){
char string[100];
printf("digite uma setença\n");
for(int i=0; string[i-1]!='\n';i++){
string[i]=getchar();
string[i+1]='\0';
}
ordem(string);
}
