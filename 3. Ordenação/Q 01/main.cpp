#include <iostream>

using namespace std;

void ordenacao(int *aux, int *aux2)
{
	int temp = *aux;
	*aux = *aux2;
	*aux2 = temp;
}

void select_sort(int vet[], int qtd, int *interacao)
{
	int i, j, min;

	for (i = 0; i < *interacao; i++)
	{
		min = i;
		for (j = i+1; j < qtd; j++)
		if (vet[j] < vet[min])
			min = j;

		ordenacao(&vet[min], &vet[i]);
	}
}

void imprimir(int vet[], int size)
{
	int i;

	for (i=0; i < size; i++)
		cout << vet[i] << " ";
}

int main()
{
  int qtd, interacao;

  cin >> qtd >> interacao;

  int vet[qtd-1];

  for(int i=0; i<qtd-1; i++)
    cin >> vet[i];

  select_sort(vet, qtd-1, &interacao);

	
	imprimir(vet, qtd-1);

	return 0;
}
