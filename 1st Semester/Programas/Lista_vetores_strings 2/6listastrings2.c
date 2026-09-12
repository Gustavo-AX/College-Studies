#include<stdio.h>


void analise(char string[]){
char v[50];
int contador=0;
for(int i=0; string[i]!='\0'; i++){
    if(string[i]>='a' && string[i]<='z'){
    if(string[i-1]==' '){
        v[contador]=string[i];
        contador++;
    }
    }
}
v[contador]='\0';
printf("\n%s\n", v);
}

int main(){
char string[100];
int N;
printf("digite o numero de frases a serem analisadas\n");
scanf("%d", &N);
getchar();
printf("digite as frases\n");
string[0]=' ';
for(int n=0;n<N;n++){
for(int i=1; string[i-1]!='\n';i++){
    string[i]=getchar();
    string[i+1]='\0';
}
analise(string);
}
}

