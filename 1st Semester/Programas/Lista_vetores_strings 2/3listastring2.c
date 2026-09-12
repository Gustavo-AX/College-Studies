#include<stdio.h>

int tamanho(char v[]){
    int contador=0;
for(int i=0;v[i]!='\0';i++){
    contador++;
}
return contador;
}

int compara(char A[], char B[]){
int verificador=1, tam;
tam=(tamanho(A)-tamanho(B));
for(int i=tam, p=0; A[i]!='\0'; i++, p++){
        if(A[i]!=B[p])
        verificador=0;

}
if(verificador==1)
    return 1;
else
    return 0;
}


int main(){
int N;
char A[1000],B[1000];
printf("qual a quantidade de casos deseja analisar?\n");
scanf("%d", &N);
int v[N];
printf("digite os numeros\n");
for(int i=0;i<N;i++){
scanf("%s %s", A, B);
if(tamanho(A)<tamanho(B))
    v[i]=0;
else{
if(compara(A,B))
    v[i]=1;
else
    v[i]=0;
}
}
for(int i=0; i<N; i++){
    if(v[i]==1)
        printf("encaixa\n");
    else
        printf("nao encaixa\n");
}
}
