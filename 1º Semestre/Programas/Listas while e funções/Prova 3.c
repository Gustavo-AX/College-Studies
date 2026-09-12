#include<stdio.h>
int potenciacontraria(int X, int expoente){
int contador=1, resultado=1;
while(contador<=expoente){
resultado=resultado*X;
contador+=1;
}
return resultado;
}

int inverso(int A){
int contador=1, somatorio=0, substituto=A, substituto1=A, X, Y;

while(substituto>10){
contador+=1;
substituto/=10;
}

while(substituto1>1){
while(contador>=1){
X=substituto1%10;
Y=potenciacontraria(X, contador);
printf("%d", Y);
somatorio=somatorio+(X*potenciacontraria(X, contador));
contador=contador-1;
substituto1/=10;
}

printf("%d", A+somatorio);
}


int main(){
int A;
printf("digite um numeros\n");
scanf("%d", &A);
printf("%d", A);
inverso(A);
}
