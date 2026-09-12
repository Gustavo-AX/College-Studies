
/*Implemente o procedimento void copia (char origem [ ], char destino [ ]) que faz uma
cópia do vetor origem no vetor destino.*/
#include<stdio.h>

int copia(char S[]){
char copiaS[100];
for(int i=0; S[i]!='\0'; i++){
    copiaS[i]=S[i];
}
printf("a copia e:\n%s", copiaS);
}




int main(){
char S[100];
char letra;
letra='X';
printf("digite uma setenca\n");
for(int i=0; letra!='\n'; i++){
letra=getchar();
S[i]=letra;
S[i+1]='\0';
}
copia(S);
}

