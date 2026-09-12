#include<stdio.h>
int copia(char origem[], char destino[], int n){
for(int i=0; i<n; i++){
destino[i]=origem[i];
destino[i+1]='\0';
}
printf("a copia e:\n%s", destino);
}



int main(){
char origem[100];
char destino[100];
char letra;
int n;
printf("digite a sentenca\n");
for(int i=0; letra!='\n'; i++){
letra=getchar();
origem[i]=letra;
origem[i+1]='\0';
}
printf("digite os n primeiros caracteres que deseja copiar\n");
scanf("%d", &n);
copia(origem, destino, n);
}
