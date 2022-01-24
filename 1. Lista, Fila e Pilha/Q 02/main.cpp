#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using std::istringstream;

using namespace std;

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}


void inserir(Lista *lista, int num){
    No *aux, *novo = (No *)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            aux = lista->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        exit(0);
}

void inserir_ordenado(Lista *lista, int num){
    No *aux, *novo = (No *)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if(novo->valor < lista->inicio->valor){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        exit(0);
}

void imprimir(Lista lista){
    No *no = lista.inicio;

    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
}

int main(){

    int  n;
    string valor, x, ordenado;
    Lista lista;

    getline(cin, x);

    criar_lista(&lista);
    getline(cin, valor);
    istringstream my_stream(valor);

    while(my_stream)
    {
        my_stream >> n;

        if(my_stream)
        {
            inserir(&lista, n);
        }
    }

    getline(cin, ordenado);
    istringstream my_stream2(ordenado);

    while(my_stream2)
    {
        my_stream2 >> n;

        if(my_stream2)
        {
            inserir_ordenado(&lista, n);
        }
    }

    imprimir(lista);

    return 0;
}
