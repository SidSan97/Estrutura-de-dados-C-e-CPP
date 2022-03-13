#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;
    int capacidade;
};

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

void busca(MinHeap* heap, int valor)
{
  for(int i=0; i<heap->size; i++)
  {
    if(heap->arr[i] != valor)
    {
      cout<<heap->arr[i]<<" ";
    }
    else
    {
      cout<<valor;
      break;
    }
  }
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
      else if(op == 2)
      {
        cin >> valor;
        busca(heap, valor);
      }
    }

    free_minheap(heap);

    return 0;
}

