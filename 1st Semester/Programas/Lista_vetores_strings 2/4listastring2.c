#include<stdio.h>

int maior(int V[], int n){
int aux=V[0];
for(int i=1;i<n;i++){
if(V[i]>aux)
aux=V[i];
}
return aux;
}

int contador_de_letras(char string[]){
int v[200];
int cont=0;
v[0]=0;
int contador=1;
for(int i=0; string[i]!='\0'; i++){
        if(string[i]>='a' && string[i]<='z'){
            if (string[i]==string[i-1]){
                contador++;
                v[cont]=contador;
                cont++;
            }
            else
                contador=1;
            }
}
printf("\na maior quantidade de letras repetidas e:%d\n", maior(v, cont));
return maior(v,cont);
}

int letra(char string[], int aux){
char caracter[200];
int cont=0;
int contador=1;
for(int i=0; string[i]!='\0'; i++){
        if(string[i]>='a' && string[i]<='z'){
            if (string[i]==string[i-1]){
                    contador++;
                }
            if(string[i]!=string[i-1])
                    contador=1;
            if(contador==aux){
            caracter[cont]=string[i];
            cont++;
            }

        }
}
caracter[cont]='\0';
printf("\nletras repetidas: %s\n", caracter);
}



void analise(char string[]){
char aux;
int help;
for(int i=0; string[i]!='\0'; i++){
    for(int n=0; string[n]!='\0';n++){
            if(string[i]<string[n]){
                    aux=string[i];
                    string[i]=string[n];
                    string[n]=aux;
            }
    }
}
help=contador_de_letras(string);
if(help==0){
printf("\nas letras mais repetidas sao:\n");
for(int i=0; string[i]!='\0'; i++){
if(string[i]>='a' && string[i]<='z')
printf("%c", string[i]);
}
printf("\n");
}
else
letra(string, help);
}

int main(){
char string[200];
int N;
printf("digite o numero de frases a serem analisadas\n");
scanf("%d", &N);
getchar();
printf("digite as frases\n");
for(int n=0;n<N;n++){
for(int i=0; string[i-1]!='\n';i++){
    string[i]=getchar();
    string[i+1]='\0';
}
analise(string);
}
}
