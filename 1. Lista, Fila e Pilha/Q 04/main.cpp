#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#define MAXTAM 7

using std::istringstream;

using namespace std;


typedef struct
{
    int item[MAXTAM];
    int topo;

}TPilha;

typedef struct
{
    int item2[MAXTAM];
    int topo2;

}auxPilha;

void inicio_pilha(TPilha *p)
{
    p->topo = -1;
}

int pilha_vazia(TPilha *p)
{
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(TPilha *p)
{
    if(p->topo == MAXTAM - 1)
        return 1;
    else
        return 0;

}

void inserir_pilha(TPilha *p, int x)
{
    if(pilha_cheia(p) == 1)
        printf("ERRO: Pilha cheia \n");
    else
    {
        p->topo++;
        p->item[p->topo] = x;
    }
}

void imprimir_pilha(TPilha *p, int cont)
{
    int aux;

        printf("%d ",p->item[p->topo]);
        for(int i= 0; i<cont-1; i++)
        {
            aux = p->item[i];
            printf("%d ", aux);
            p->topo++;
        }
}

int remover_pilha(TPilha *p)
{
    int aux;

    if(pilha_vazia(p))
       exit(0);
    else
    {
        aux = p->item[p->topo];
        p->topo--;

    }

     return aux;
}

int main()
{
    string valores, x;
    int n, cont = 0;
    TPilha *p = (TPilha *)malloc(sizeof(TPilha));

    getline(cin, x);

    inicio_pilha(p);

    getline(cin, valores);
    istringstream my_stream(valores);

    while(my_stream)
    {
        my_stream >> n;

        if(my_stream)
        {
            cont++;
            inserir_pilha(p, n);
        }
    }

    imprimir_pilha(p, cont);


    return 0;
}
