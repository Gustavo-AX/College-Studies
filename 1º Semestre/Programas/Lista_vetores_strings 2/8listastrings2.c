#include<stdio.h>
int main(){
int N[1000], T, aux=0;
printf("digite um numero entre 2 e 50\n");
scanf("%d", &T);
if(T>=2 && T<=50){


for(int i=0; i<1000; i++){
    printf("N[%d] = %d\n", i, aux );
    aux++;
    if(aux>(T-1))
    aux=0;

}
}
else
    printf("numero invalido");
}
