/*19) Implemente um procedimento para calcular e exibir o seguinte
somatório:
S = f(1)/1 + f(2)/2 + f(3)/3 + ... + f(100)/100. A função f(n) foi definida no
exercício anterior.
Resultado: 11363107*/
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
int denominador=0, contador, resultado=0, somatorio=0;
for( contador=1; contador<=100; contador++){
denominador=multiplo(contador);
resultado=denominador/contador;
somatorio=somatorio+resultado;
}
printf("somatorio:%d", somatorio);
}
