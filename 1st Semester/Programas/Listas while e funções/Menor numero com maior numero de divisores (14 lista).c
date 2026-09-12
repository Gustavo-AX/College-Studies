#include<stdio.h>
int contadordedivisores (int numero);
int main(){
int numero=1, bruno=0, divisor=1;
for (numero=1; numero<=10000; numero++){
if(contadordedivisores(numero)>divisor){
    divisor=contadordedivisores(numero);
    bruno=numero;
}
}
printf ("%d %d", bruno, divisor);
}
int contadordedivisores(int numero){
int divisores=1, numerodedivisores=0;
for (divisores=1;divisores<=numero/2;divisores++){
    if (numero%divisores==0)
    numerodedivisores=numerodedivisores+1;
}
return numerodedivisores+1;
}
//we increase one number in the end, because we are counting just until the half of the number, and this don't include the own number, and all numbers are divisible by itself.
