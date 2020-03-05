#include <stdio.h>
#include <stdlib.h>
int num = 9;

typedef struct linkedList
{
    int cont;
    struct linkedList *next;
}cel;
int main()
{
    int i;
    int vet[10];
	for (i=0; i<num; i++)
    {
		vet[i] = rand () %10;
	}
	cel *lst;
	lst = malloc(sizeof(cel));
	lst->cont = NULL;
	lst->next = NULL;
	vectToList(num, vet, lst);
	displayList(lst);
}

void displayList(cel *lst)
{
    if (lst != NULL)
    {
        printf("%d, ", lst->cont);
        displayList(lst->next);
    }
    printf("\n");
}

void vectToList(int num, int vet[], cel *lst)
{
    if(num >= 0)
    {
        cel *noval;
        noval = malloc(sizeof(cel));
        noval->cont = vet[num];
        noval->next = lst->next;
        lst->next = noval;
        vectToList(num-1, vet, lst);
    }
    return;
}
