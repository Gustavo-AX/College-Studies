#include<stdio.h>
int multiplo(int n){
int contador=1, validador=0, substituto;
for( ; 1; contador++){
    substituto=n*contador;
    while (validador!=1 && substituto>9){
        if (substituto%10<=2) substituto/=10;
        else validador=1;
        }
if(substituto%10<=2) return n*contador;
validador=0;
}
}

int main(){
int n;
char letra;
letra = 'X';
while(letra!='F'){
printf("digite um numero\n");
scanf("%d", &n);
printf("o minimo multiplo desse numero, composto apenas por algarismos de 0 a 2, e %d\n\n", multiplo(n));
printf("deseja continuar? Se sim, digite enter, se nao, digite F\n\n");
letra=getche();
}
}
