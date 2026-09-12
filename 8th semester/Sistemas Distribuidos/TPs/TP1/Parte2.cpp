#include <pthread.h>
#include <semaphore.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <iostream>
#include <random>
#include <atomic>
#include <cmath>
#include <cstdlib>

using namespace std;

int N = 10;
int Np = 1;
int Nc = 1;
const int M = 100000;

vector<int> buffer;
int in = 0, out = 0;
int count = 0;

sem_t posicoes_vazias;
sem_t posicoes_ocupadas;
sem_t mutex; // Exclusão Mutua

atomic<int> totalConsumidos(0);
atomic<int> itens_a_produzir(M);
vector<int> ocupacao;

bool isprime(int number){
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    int limit = (int)std::sqrt(number);
    for (int i = 3; i <= limit; i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

void* produtor(void*) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10000000);

    while (true) {
        // diminui os itens que devem ser produzidos
        int prod = itens_a_produzir.fetch_sub(1);
        if (prod <= 0) {
            itens_a_produzir.fetch_add(1);
            break;
        }

        int num = dist(gen);

        sem_wait(&posicoes_vazias);
        sem_wait(&mutex);

        buffer[in] = num;
        in = (in + 1) % N;
        count++;         
        ocupacao.push_back(count);

        sem_post(&mutex);
        sem_post(&posicoes_ocupadas);
    }
    return nullptr;
}

void* consumidor(void*) {
    while (true) {
        if (totalConsumidos.load() >= M) {
            break;
        }

        sem_wait(&posicoes_ocupadas);
        sem_wait(&mutex);

        if (totalConsumidos.load() >= M) {
            sem_post(&mutex);
            sem_post(&posicoes_ocupadas);
            break;
        }

        int num = buffer[out];
        out = (out + 1) % N;
        count--;                   
        ocupacao.push_back(count);

        totalConsumidos.fetch_add(1);

        sem_post(&mutex);
        sem_post(&posicoes_vazias);

        if (isprime(num)) {
            // não printa
        }
    }
    return nullptr;
}

int main(int argc, char* argv[]) {

    buffer.resize(N, 0);

    sem_init(&posicoes_vazias, 0, N);
    sem_init(&posicoes_ocupadas, 0, 0);
    sem_init(&mutex, 0, 1);

    vector<pthread_t> produtores_threads(Np);
    vector<pthread_t> consumidores_threads(Nc);

    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < Np; i++)
        pthread_create(&produtores_threads[i], nullptr, produtor, nullptr);

    for (int i = 0; i < Nc; i++)
        pthread_create(&consumidores_threads[i], nullptr, consumidor, nullptr);

    for (int i = 0; i < Np; i++)
        pthread_join(produtores_threads[i], nullptr);

    for (int i = 0; i < Nc; ++i) {
        sem_post(&posicoes_ocupadas);
    }

    for (int i = 0; i < Nc; i++)
        pthread_join(consumidores_threads[i], nullptr);

    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Execução concluída.\n";
    cout << "Tempo total: " << duracao.count() << " segundos\n";

    ofstream f("ocupacao.txt");
    for (int o : ocupacao)
        f << o << "\n";
    f.close();

    cout << "Arquivo 'ocupacao.txt' gerado com " << ocupacao.size() << " amostras.\n";

    sem_destroy(&posicoes_vazias);
    sem_destroy(&posicoes_ocupadas);
    sem_destroy(&mutex);

    return 0;
}
