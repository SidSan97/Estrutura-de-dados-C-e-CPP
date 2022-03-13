#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct no
{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir(NoArv *raiz, int num)
{
    if(raiz == NULL)
    {
        NoArv *aux = (NoArv *)malloc(sizeof(NoArv));

        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;

        return aux;
    }
    else
    {
        if(num < raiz->valor)
        {
            raiz->esquerda = inserir(raiz->esquerda, num);
        }
        else
        {
            raiz->direita = inserir(raiz->direita, num);
        }
        return raiz;
    }
}

void imprimir_pos_ordem(NoArv *raiz)
{
    if(raiz)
    {
        imprimir_pos_ordem(raiz->esquerda);
        imprimir_pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

int main()
{
   NoArv *raiz = NULL;
   int op, valor;

   cin >> op;

   for(int i=0; i<op; i++)
   {
       cin>>valor;
       raiz = inserir(raiz, valor);
   }


   imprimir_pos_ordem(raiz);


    return 0;
}

