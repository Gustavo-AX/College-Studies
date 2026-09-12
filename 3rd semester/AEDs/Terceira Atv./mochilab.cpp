#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>

using namespace std;

int[] bestbag(pair<int,int> items, int numberitems){
int tablesize=pow(2,numberitems);
    for(int i=0;i<tablesize; i++){
        

    }


}

int main(){
    FILE *file;
    char fileName[100];
    int numberbag, bagsize, numberitems;
    pair <int,int> infoitem;
    bool itemvalue;

    printf("Digite o nome do arquivo: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r"); // abertura do arquivo no modo leitura
    if (!file)
    {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    };

    //leitura das mochilas e seus tamanhos
    fscanf(file, "%i", &numberbag);
    int bags[numberbag];
    for(int i=0; i<numberbag; i++){
        fscanf(file, "%i", &bagsize);
        bags[i]=bagsize;
    }

    //leitura dos itens
    fscanf(file, "%i", &numberitems);
    pair<int,int> items[numberitems];
    int a,b; //auxiliar do pair
    for(int i=0; i<numberitems; i++){
        //as posições impares se tratam do número do item 
        fscanf(file, "%i %i", &a, &b);
        infoitem = make_pair(a,b);
        items[i]=infoitem;
    }

    //leitura da mochila
    bool infobag[numberitems][numberbag];
    for(int i=0; i<numberitems; i++){
        for(int j=0; j<numberbag; j++){
            fscanf(file, "%i", &itemvalue);
            infobag[i][j]=itemvalue;
        }
    }

    /*for(int i=0; i<numberitems; i++){
        for(int j=0; j<numberbag; j++){
            printf("%i", infobag[i][j]);
        }
        printf("\n");
    }*/


    
return 0;
}