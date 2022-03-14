
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int particao (int vet[], int min, int max, int *p1)
{
	int pivot = vet[max]; 
	int i = (min - 1); 
  *p1 = pivot;

	for (int j = min; j <= max - 1; j++)
	{
		
		if (vet[j] < pivot)
		{
			i++; 
			swap(&vet[i], &vet[j]);
		}
	}
	swap(&vet[i + 1], &vet[max]);
	return (i + 1);
}

void quickSort(int vet[], int min, int max, int *p1)
{
  int &pivot1 = *p1;
  
	if (min < max)
	{

		int pi = particao(vet, min, max, &pivot1);

		quickSort(vet, min, pi - 1, p1);
		quickSort(vet, pi + 1, max, p1);
	}
}

void imprimir(int vet[], int size, int *p1)
{
  cout <<vet[0]<<" "<<*p1<<" ";
	for (int i = 0; i < size; i++)
		cout << vet[i] << " ";
}

int main()
{

  int qtd, mainPivot, p1;

  cin >> qtd >> mainPivot;
  int vet[qtd-1];

  for(int i=0; i < qtd-1; i++)
    cin >> vet[i];
  

	quickSort(vet, 0, (qtd-1) - 1,&p1);

	imprimir(vet, qtd-1, &p1);
	return 0;
}


