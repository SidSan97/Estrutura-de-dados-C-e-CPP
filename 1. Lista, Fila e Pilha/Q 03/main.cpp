#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserir_no_fim(Lista *lista, int num){
    No *novo = (No *)malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        if(lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else{
            lista->fim->proximo = novo;
            lista->fim = novo;
            novo->proximo = lista->inicio;
        }
        lista->tam++;
    }
    else
        exit(0);
}

void imprimir(Lista lista, int pos, int soma){
    No *no = lista.inicio;

    int cont = -1, aux2, pos2;
    int vet[6];

    for(int i=0; i<6; i++)
    {
        vet[i] = no->valor;
        no = no->proximo;
    }

     for(int i = pos+1; i < soma+pos; i++)
     {
         if(cont < 0)
            cont = i;

         if(cont == 6)
          cont = 0;

         aux2 = vet[cont];

         cont++;
     }

     for(int i = 0; i<6; i++)
     {
         if(vet[i] == aux2)
            pos2 = i;
     }

     if(aux2 == 0)
        pos2 = 0;

     cout<<pos2<<endl;
}

int main(){

    int valor, x, pos, soma = 0;
    Lista lista;

    criar_lista(&lista);

    cin >> x;

    for(int i=0; i<6; i++)
    {
        cin >> valor;
        soma += valor;
        inserir_no_fim(&lista, valor);
    }

    cin >> pos;

    imprimir(lista, pos, soma);

    return 0;
}
