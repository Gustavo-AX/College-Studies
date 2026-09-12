/*Implemente procedimentos para: eliminar os números repetidos da matriz. Os números repetidos devem ser substituídos por
novos números. Este procedimento deverá exibir na tela todos os elementos da matriz antes e
depois de eliminar os números repetidos.*/
#include<stdio.h>
#include<stdlib.h>

const int valor;
const int x;
const int y;

int eliminar(int matriz[x][y]){
int verificador;
for(int m=0;m<x;m++){
for(int n=0; n<y; n++){
	for(int a=0; a<x; a++){
	for(int b=0;b<y;b++){
	if(matriz[m][n]==matriz[a][b] && (a!=m || b!=n)){
    verificador=0;
    while(verificador!=1){
		verificador=1;
		matriz[m][n]=rand()%(valor+1);
		for(int a=0; a<x; a++){
		for(int b=0;b<y;b++){
		if(matriz[m][n]==matriz[a][b] && (a!=m || b!=n))
		verificador=0;
		}
		}
		}
}
}
}
}
}
printf("\nos numeros sem repetir:\n");
for(int m=0;m<x;m++){
for(int n=0; n<y;n++){
printf("%d\t", matriz[m][n]);
}
printf("\n");
}

printf("\n");
printf("\nordem crescente da matriz:\n");
int substituto=matriz[0][0];

for(int m=0;m<x;m++){
for(int n=0; n<y; n++){
    for(int a=0;a<x;a++){
    for(int b=0; b<y; b++){
            if(matriz[m][n]<matriz[a][b]){
            substituto=matriz[m][n];
            matriz[m][n]=matriz[a][b];
            matriz[a][b]=substituto;
            }
    }
    }
}
}
for(int m=0;m<x;m++){
for(int n=0; n<y;n++){
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
}




int main(){

printf("digite quantas linhas deseja ter na matriz\n");
scanf("%d", &x);
printf("digite quantas colunas deseja ter na matriz\n");
scanf("%d", &y);
printf("digite o maior valor para uma entrada da matriz\n");
scanf("%d", &valor);
int matriz[x][y];

for(int m=0;m<x;m++){
for(int n=0; n<y;n++){
matriz[m][n]=rand()%(valor+1);
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
eliminar(matriz);
}
