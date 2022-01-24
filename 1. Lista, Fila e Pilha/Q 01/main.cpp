#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using std::istringstream;

using namespace std;

int tamanho;
float vetor []={};

 typedef struct lista
 {
    float info;
    struct lista* prox;
 }Lista;

 Lista* criar_lista()
 {
    return NULL;
 }

 Lista* inserir_lista (Lista* L1, float i)
 {
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->info = i;
    novo->prox = L1;

    return novo;
 }


 void imprimir_conc(float concatenado[])
 {

    for(int i=tamanho-1; i>=0; i--)
        cout << vetor[i]<<" ";
 }

 void conc (Lista* L1, Lista* L2, int tamanho)
 {
    int contador = -1;

    for(int i=0; i<tamanho; i++)
    {
        if(i%2 == 0)
        {
            contador++;
            vetor[contador] = L1->info;
            L1 =L1->prox;
        }
        else if(i%2 == 1)
        {
            contador++;
            vetor[contador] = L2->info;
            L2 =L2->prox;
        }

        void imprimir_conc(float vetor[]);
    }
 }

 int main()
 {
    Lista* L1;
    Lista* L2;

    int cont1 = 0, cont2 = 0;
    string valor1, valor2, X;
    float n;

    getline(cin, X);

    L1 = criar_lista();
    getline(cin, valor1);
    istringstream my_stream(valor1);

    while(my_stream)
    {
        my_stream >> n;

        if(my_stream)
        {
            cont1++;
            L1 = inserir_lista(L1, n);
        }
    }


    L2 = criar_lista();
    getline(cin, valor2);
    istringstream my_stream2(valor2);

    while(my_stream2)
    {
        my_stream2 >> n;

        if(my_stream2)
        {
            cont2++;
            L2 = inserir_lista(L2, n);
        }
    }

    tamanho = cont1 + cont2;

    conc(L1,L2, tamanho);
    imprimir_conc(vetor);

    return 0;
 }
