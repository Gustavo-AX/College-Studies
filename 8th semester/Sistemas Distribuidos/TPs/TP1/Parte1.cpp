#include <stdio.h>      // printf, perror
#include <stdlib.h>     // exit, rand, srand
#include <unistd.h>     // fork, pipe, read, write, close
#include <sys/types.h>  // pid_t
#include <string.h>     // strlen, memset, snprintf
#include <time.h>       // time (para semente randômica)
#include <sys/wait.h>

// A implementação desse código se baseou nesse vídeo:
// https://www.youtube.com/watch?v=Mqb2dVRe0uo
// Com modificações.

// Rode o programa sobre o linux, pois rodar sobre o windows irá gerar erros.

bool isprime(int number){
    int div = 0;
    for(int i = 1; i <= number; i++){
        if(number%i == 0){
            div++;
        }
    }

    if(div == 2)
        return true;

    return false;
}

int main(int args, char* argv[]){
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(nullptr));

    int fd[2];
    // fd[0] = leitura
    // fd[1] = escrita
    // A função de criar o pipe retorna zero se der certo e -1 se der errado

    if(pipe(fd) == -1){
        printf("Deu erro ao criar o pipe");   
    }

    int id = fork();

    if(id == -1){
        printf("Deu ruim para criar o fork");
    }

    
    if(id > 0){
        // Processo pai
        close(fd[0]);
        int x = rand() % 100 + 1; 
        char buffer[20]; // buffer fixo de 20 bytes

        for(int i = 0; i < 100; i++){
            int delta = rand() % 100 + 1; // ∆ ∈ [1,100]
            x = x + delta;

            // Converte int para string:
            snprintf(buffer, sizeof(buffer), "%d", x);

            if(write(fd[1], buffer, 20) == -1){
                printf("Deu ruim na escrita do pipe");
                return 2;
            }
        }

        // Envia sinal de término
        snprintf(buffer, sizeof(buffer), "%d", 0);

        if(write(fd[1], buffer, 20) == -1){
            printf("Deu ruim no fim");
        }

        close(fd[1]);
        wait(NULL);  // espera o processo filho terminar
    } else {
        // Processo filho
        close(fd[1]);
        char buffer[20];

        int y;
        int r;
        while((r = read(fd[0], buffer, 20)) > 0){

            y = atoi(buffer); // string -> int
            if(y == 0) {
                // recebido sinal end
                printf("fim recebido \n");
                break;
            }
            printf("%d %s\n", y, isprime(y) ? "é primo" : "não é primo");
        }

        if(r == -1){
            printf("deu ruim");
            return 0;
        }
        close(fd[0]);
    }
    return 0;
}