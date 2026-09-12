/*Implemente um programa que preenche com valores aleatórios uma matriz MxN e:
1. armazena em um vetor v1 o maior elemento cadastrado em cada coluna da matriz;
2. armazena em um vetor v2 o menor elemento cadastrado em cada coluna da matriz;
Ao final, o programa deve exibir: a matriz original, o vetor dos maiores elementos e o vetor dos
menores elementos.
Obs.:
­ Os valores de M e N devem ser definidos por meio da diretiva “#define”
­ Você pode utilizar no máximo dois comandos “for” para encontrar os menores e maiores
elementos das colunas.
A solução deve ser implementada no programa principal (“main”), sem utilizar funções.*/
#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 10
int main(){
int matriz[M][N], V1[N],V2[N];
for(int m=0;m<M;m++){
for(int n=0; n<N;n++){
matriz[m][n]=rand()%21;
printf("%d\t", matriz[m][n]);
}
printf("\n");
}
for(int y=0;y<N;y++){
V1[y]=matriz[0][y];
V2[y]=matriz[0][y];
for(int x=0; x<N; x++){
if(matriz[x][y]>V1[y])
    V1[y]=matriz[x][y];
if(matriz[x][y]<V2[y])
    V2[y]=matriz[x][y];
}
}
printf("\nv1 e:\n");
for(int i=0;i<N;i++){
    printf("%d\t", V1[i]);
}
printf("\nv2 e:\n");
for(int i=0;i<N;i++){
    printf("%d\t", V2[i]);
}
}





