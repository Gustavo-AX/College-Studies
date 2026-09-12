#include <stdio.h>
#include <string.h>
int main(){
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file;
    char fileName[100];

    printf("digite o nome do arquivo\n");
    int i = 0;
    for (i = 0; i < 99 && (fileName[i - 1] != '\n'); i++)
    {
        scanf("%c", &fileName[i]); // dessa forma, nomes que contem espaço no meio também são aceitos
    }
    fileName[i - 1] = '\0'; // defino o fim da string
    printf("\n");

    file = fopen(fileName, "r"); // abertura do arquivo no modo leitura
    if (!file)
    {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    };

    int aux, m_box = 0, n_box = 0, soma = 0, soma_temp; // declaração das variáveis
    fscanf(file, "%i", &aux);
    int matriz[aux][aux]; // declaração da matriz
    for (int m = 0; m < aux; m++)
    {
        for (int n = 0; n < aux; n++)
        {
            if (n <= m)
            { // define as entradas em forma de pirâmide, ou seja, primeira linha tem uma coluna, segunda fileira duas colunas;
                fscanf(file, "%i ", &matriz[m][n]);
                soma_temp = 0;
                for (int i = 0; i < m; i++)
                { // i deve ser menor que m, pois quero pegar só as linhas acima
                    for (int j = 0; j < aux; j++)
                    {
                        soma_temp = soma_temp + matriz[i][j]; // faz a soma a soma de todos aqueles que vem em cima dele
                    }
                }
                soma_temp = soma_temp + matriz[m][n]; // somo com a caixa escolhida

                if (n == 0 && m == 0)
                {
                    soma = soma_temp; // pega o primeiro caso para comparar os proximos
                }
                else if (soma < soma_temp)
                { // caso venha um maior, gravo a soma e a caixa
                    soma = soma_temp;
                    m_box = m;
                    n_box = n;
                }
            }
            else
            {
                matriz[m][n] = 0; // inicializar as demais entradas como zero;
            }

            printf("%i ", matriz[m][n]); // mostra as colunas da matriz
        }
        printf("\n"); // salta linha
    }
    printf("soma = %i, linha = %i, coluna =%i\n", soma, m_box + 1, n_box + 1); // mostra a soma e local da caixa

    fclose(file); // fecha arquivo

    return 0;
}
