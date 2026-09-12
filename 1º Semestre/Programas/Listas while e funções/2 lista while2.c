#include<stdio.h>
int funcao(int A, int B){
int momento=0, contador=0,substituto=0, X;
printf("A=%d B=%d", A,B);
for( ; momento<=9; momento++){
    for(substituto=A; substituto<=B; substituto++){
        X=substituto;
        while(X>=1){
        if(X%10==momento)
            contador+=1;
        X/=10;
        }
    }
printf(" %d", contador);
contador=0;
}
}

int main(){
int A,B;
char letra;
letra='X';
while(letra!='F'){
printf("\ndigite dois numeros, em ordem crescente, referentes ao intervalo a ser analisado\n");
scanf("%d %d", &A, &B);
funcao(A,B);
printf("\n\ndeseja continuar? Se sim, tecle 'enter', se não, tecle 'F'\n");
letra=getche();
}
}
