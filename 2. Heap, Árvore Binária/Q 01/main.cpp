#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct no
{
	int valor;
	struct no *esq;
	struct no *dir;
}no;

typedef struct arvore
{
	struct no *raiz;
	int total;
}arvore;

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;
    int capacidade;
};

//DECLARAÇÃO DAS FUNÇOES DE ARVORE 'HIPADA'
arvore *criar_arvore();
no *criar_no(int);
void inserir(no *, arvore *);
void inserir_no(no *, no *, int);
void imprimir_em_ordem(no *);

int parent(int i) {
    return (i - 1) / 2;
}

int no_esq(int i) {
    return (2*i + 1);
}

int no_dir(int i) {
    return (2*i + 2);
}

int get_min(MinHeap* heap) {

    return heap->arr[0];
}

MinHeap* init_minheap(int capacidade)
{
    MinHeap* minheap = (MinHeap*) calloc (1, sizeof(MinHeap));
    minheap->arr = (int*) calloc (capacidade, sizeof(int));
    minheap->capacidade = capacidade;
    minheap->size = 0;
    return minheap;
}

MinHeap* insert_minheap(MinHeap* heap, int element)
{

    if (heap->size == heap->capacidade)
    {
        exit(0);
        return heap;
    }

    heap->size++;
    heap->arr[heap->size - 1] = element;

    int curr = heap->size - 1;

    while (curr > 0 && heap->arr[parent(curr)] > heap->arr[curr])
    {
        int temp = heap->arr[parent(curr)];
        heap->arr[parent(curr)] = heap->arr[curr];
        heap->arr[curr] = temp;
        curr = parent(curr);
    }
    return heap;
}

MinHeap* heapify(MinHeap* heap, int index)
{
    if (heap->size <= 1)
        return heap;

    int esquerda = no_esq(index);
    int direita = no_dir(index);

    int menor_chave = index;

    if (esquerda < heap->size && heap->arr[esquerda] < heap->arr[index])
        menor_chave = esquerda;

    if (direita < heap->size && heap->arr[direita] < heap->arr[menor_chave])
        menor_chave = direita;

    if (menor_chave != index)
    {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[menor_chave];
        heap->arr[menor_chave] = temp;
        heap = heapify(heap, menor_chave);
    }

    return heap;
}

MinHeap* deletar(MinHeap* heap)
{
    if (!heap || heap->size == 0)
        return heap;

    int size = heap->size;
    int last_element = heap->arr[size-1];

    heap->arr[0] = last_element;

    heap->size--;
    size--;

    heap = heapify(heap, 0);
    return heap;
}

MinHeap* delete_element(MinHeap* heap, int valor)
{
    int index = -1;

    for(int i=0; i<heap->size; i++)
    {
        if(heap->arr[i] != valor)
            index++;
        else
            break;
    }
    index++;

    heap->arr[index] = get_min(heap) - 1;

    int curr = index;

    while (curr > 0 && heap->arr[parent(curr)] > heap->arr[curr])
    {
        int temp = heap->arr[parent(curr)];
        heap->arr[parent(curr)] = heap->arr[curr];
        heap->arr[curr] = temp;
        curr = parent(curr);
    }

    heap = deletar(heap);
    return heap;
}

void free_minheap(MinHeap* heap)
{
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main()
{
    arvore *arv = criar_arvore();
    int op, valor, qtd;

    cin >> qtd;
    MinHeap* heap = init_minheap(qtd);

    for(int i=0; i<qtd; i++)
    {
      cin >> op;

      if(op == 1)
      {
        cin >> valor;
        insert_minheap(heap, valor);
      }
      else if(op == 0)
      {
        cin >> valor;
        delete_element(heap, valor);
      }
    }

    for(int i=0; i<heap->size; i++)
    {
      inserir(criar_no(heap->arr[i]), arv);
    }

    free_minheap(heap);

    imprimir_em_ordem(arv->raiz);
    return 0;
}

//INSERÇÃO NA ARVORE EM FORMA HEAP
arvore *
criar_arvore(){
	arvore *a = (arvore *) malloc (sizeof(arvore));
	a->raiz = NULL;
	a->total = 0;

	return a;
}

no *
criar_no(int q){
	no *n = (no *) malloc (sizeof(no));
	n->valor = q;
	n->esq = NULL;
	n->dir = NULL;

	return n;
}

void inserir(no *n, arvore *a){
	if (a->raiz == NULL){
                a->raiz = n;
        }else{
		inserir_no(n, a->raiz, a->total);
	}
	a->total = a->total+1;
}

void inserir_no(no *n, no *raiz, int total)
{
	struct no *fila[total];
	int i = 0, v = 0;
	no *posicao = raiz;
	do
    {
		if(posicao->esq == NULL){
			posicao->esq = n;
			break;
		}else{
			fila[i] = posicao->esq;
			i++;
			if(posicao->dir == NULL){
				posicao->dir = n;
				break;
			}else{
				fila[i] = posicao->dir;
				i++;
			}
		}
		posicao = fila[v];
		v++;

	}while(1);
}

void imprimir_em_ordem(no *raiz)
{
	if (raiz != NULL)
    {
		imprimir_em_ordem(raiz->esq);
		cout <<raiz->valor<<" "<<" ";
        //printf("%d ", raiz->valor);
		imprimir_em_ordem(raiz->dir);
	}
}
