#include <iostream>

using namespace std;

void bubble_sort(int vet[], int N, int *interacao)
{
  int aux, i, j;

  for(i=1; i < *interacao+1; i++)
  {
    for(j=0; j<N-1; j++)
    {
      if(vet[j] > vet[j+1])
      {
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
      }
    }
  }
}

void imprimir(int vet[], int n)
{
  for(int i=0; i<n; i++)
    cout << vet[i] <<" ";
}

int main() 
{
  int qtd, interacao;

  cin >> qtd >> interacao;

  int vet[qtd-1];

  for(int i=0; i<qtd-1; i++)
    cin >> vet[i];

  bubble_sort(vet, qtd-1, &interacao);

  imprimir(vet, qtd-1);

}