#include <stdio.h>
#include <vector>

using namespace std;

int number;          // o numero que vai ser decomposto
bool checker = false; // determina se estou ou não no meio de uma decomposição
vector<int> vec;      // vetor que guarda os numeros decompostos
int verificador = 0; // usado para saber em qual ponto da decomposição estou
//  eu paro o verificador quando o numero de 1's na decomposição for igual a numero-sendo-decomposto
int temp;
/*
Defini temp como o primeiro numero da decomposição
5
4+1 (temp =4)
3+2 (temp =3)
3+1+1 (temp =3) ...
*/

// recebe como argumentos o número a ser decomposto e a partir de qual numero ele vai ser decomposto
void dec2(int decom, int ref)
{
    if (!checker)
    {
        int aux = ref;
        int div = decom / ref;
        if ((div) > 1 && (ref != 1)) // se ref for menor que a metade do numero, repito ele e acho o complemento (serve para o primeiro caso)
        {
            for (int i = 0; i < div; i++)
            {
                vec.push_back(ref);
            }

            aux = decom % ref;
            if (aux != 0)
                vec.push_back(aux);
        }
        else
        {
            while (ref + aux > (number)) // se ref for grande, eu procuro o complementar dele em relação a number
            {
                aux--;
            }
            vec.push_back(ref);
            vec.push_back(aux);
        }
    }
    else
    {
        // aqui ref sempre sera ref=decom -1, sendo assim só preciso achar o complementar de number com relação a temp
        int temp = 0;
        int aux = ref;
        int tam = vec.size();

        for (int i = 0; i < tam; i++)
        {
            temp += vec[i]; // somo todos os numeros atras do numero que estou decompondo
        }
        //printf("temp: %i, ", temp);
        //printf("decom = %i, ref = %i ", decom, ref);
        if ((number - temp) / ref > 1) // se quando eu decompor, existir um numero>1 que repetido, complementa temp para chegar a number, eu repito ele
        {
            for (int i = 0; i < (number - temp)/ref; i++)
            {
                vec.push_back(ref);
            }
            if ((number - temp) % ref > 0)
                vec.push_back((number - temp) % ref);
        }
        else
        {
            while (ref + aux > (number - temp)) // se ref for grande, eu procuro o complementar dele
            {
                aux--;
                if (aux == 1)
                    break;
            }
            vec.push_back(ref);
            vec.push_back(aux);
        }
        //confiro se está tudo certo, se tiver faltando um 1, eu complemento
        tam = vec.size();
        temp = 0;
        for (int i = 0; i < tam; i++)
        {
            temp += vec[i]; // somo todos os numeros
        }
        //printf("temp: %i \t", temp);
        if (temp != number)
        {
            for (int i = 0; i <= (number - temp); i++) //se por acaso faltar um 1, eu adciono ele no final, mas não é para faltar
            {
                vec.push_back(1);
            }
        }
    }
}

// eu pego os os numeros da decomposição e coloco eles em um array, decompondo sempre o último se necessário
int dec()
{
    int aux = temp;

    if (!checker) // no primeiro ciclo, eu vou pegar a primeira decomposição, e depois vou decompor essa decomposição da dir p/ esq
    {
        dec2(number, aux);
        checker = true;
    }
    else
    {
        for (int i = (vec.size() - 1); i > 0; i--) // i>0 pq não quero pegar o temp, vou da direita p/ esquerda pegando numeros > 1
        {
            if (vec[i] != 1)
            {
                aux = vec[i];
                vec.erase(vec.begin() + i);
                dec2(aux, aux - 1);
                break;
            }
            else
            {
                vec.erase(vec.begin() + i); // apagar os 1's, depois volto todos eles no fim do vector
            }
        }
    }
    // no final eu só tenho 1's, logo, eu confiro se cheguei ao final, se sim, coloco no vector number*1's
    if (temp == 1)
    {
        vec.clear();
        for (int i = 0; i < number; i++)
        {
            vec.push_back(1);
        }
    }
    // imprimir a string:
    int tam = vec.size();
    for (int i = 0; i < tam - 1; i++)
    {
        printf("%i + ", vec[i]);
        if (vec[i] == 1)
            verificador++;
    }
    verificador++;
    printf("%i\n", vec[(vec.size() - 1)]);

    // Se eu chegar ao final de temp, diminuo temp;
    if (verificador == (number - temp))
    {
        temp--;
        vec.clear();
        checker = false;
    }
    // se o verificador indicar que acabou, não chamo mais a função;
    if ((verificador != (number)))
    {
        verificador = 0;
        return 0;
    }
    else
        return 1;
}

int main()
{
    printf("Digite um numero inteiro: ");
    scanf("%i", &number);
    int verificador_final = 0;
    // casos especiais: 0 e 1, podem causar problemas na minha logica, entao trato eles separados
    if (number != 0)
    {
        if (number > 1)
            temp = (number - 1);
        else
            temp = 1;
        printf("Decomposicao:\n%i\n", number);
    }
    else
    {
        printf("Decomposicao:\n%i\n0\n", number);
        verificador_final = 1;
    }

    while (verificador_final != 1)
    {
        verificador_final = dec();
    }
}