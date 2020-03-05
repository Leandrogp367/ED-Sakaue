#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ex = 1;
int num = 100;
int naux;

int main()
{
    int n = 0;
    int i;
    srand(time(NULL));
	int vet[num];
	for (i=0; i<num; i++)
    {
		vet[i] = rand () %100;
	}

    ex++;
	printf("Exercicio: %d \n", ex);

	printf("insira um numero inteiro: ");
	scanf("%d", &n);
    naux = n;
    countToZero(n, naux);
    printf("\n");

    ex++;
	printf("Exercicio: %d \n", ex);
	printf("Vetor inicial: ");
	for (i = 0; i < num; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

	invertVetor(num-1, 0, vet);

	printf("Vetor invertido: ");
	for (i = 0; i < num; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void invertVetor(int n, int pos, int vet[])
{
    if(vet != NULL)
    {
        if((n - pos) > 0 )
        {
            int aux = vet[n];
            vet[n] = vet[pos];
            vet[pos] = aux;

            return invertVetor(n-1, pos+1, vet);
        }
        else
        {
            return 0;
        }
    }
}

void countToZero(int n, int naux)
{
    if (n == -naux)
    {
        printf("%d", naux);
        return abs(n);
    }
    else
    {
        printf("%d ", abs(n));
        countToZero(n - 1, naux);
    }
}
