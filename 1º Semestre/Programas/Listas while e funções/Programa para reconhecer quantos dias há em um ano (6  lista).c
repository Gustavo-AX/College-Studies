#include<stdio.h>
int bissexto(int ano);
int dias(int mes, int ano);

int main(){
int ano, mes, dia, somadosdiasdosmeses, diastotais;
printf("digite o ano:\n");
scanf("%d", &ano);
printf("digite o mes\n");
scanf("%d", &mes);
printf("digite o dia\n");
scanf("%d", &dia);
somadosdiasdosmeses = dias(mes, ano);
diastotais= somadosdiasdosmeses+dia;
printf("a numero de dias ate hoje e: %d", diastotais);
}

int dias(int mes, int ano){
int soma=0, month=0;
for( ;month<mes; ++month){
if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    soma = soma+31;
if (month==4 || month==6 || month==9 || month==11)
    soma=soma+30;
if(month==2)
    soma=soma+28;
}
if(bissexto(ano)==1)
    soma=soma+1;
return soma;
}

int bissexto(int ano){
if((ano%100!=0 && ano%4==0)||(ano%100==0 && ano%400==0))
return 1;
else
return 0;
}
