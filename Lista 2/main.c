#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int cont;
    struct linkedList *next;
}cel;

int main()
{
    int n;
    int i;
    int num;
    int num2;
    int vet[10];
    cel *lst;
    cel *lst2;
    cel *lstCon;
    cel *lstVect;
    cel *lstIntercal;
    lst = malloc(sizeof(cel));
    lst->next = NULL;
    lst2 = malloc(sizeof(cel));
    lst2->next = NULL;
    lstCon = malloc(sizeof(cel));
    lstCon->next = NULL;
    lstVect = malloc(sizeof(cel));
    lstVect->next = NULL;
    lstIntercal = malloc(sizeof(cel));
    lstIntercal->next = NULL;
	for (i=0; i<num; i++)
    {
		vet[i] = rand () %10;
	}

	printf("insira quantas celulas deseja criar na primeira lista: ");
    scanf("%d", &num);
    printf("insira quantas celulas deseja criar na segunda lista: ");
    scanf("%d", &num2);
    inserir(num, n, lst);
    inserir2(num2, n, lst2);
    printf("Lista 1: \n");
    display(lst);
    printf("Lista 2: \n");
    display(lst2);

    printf("Exercicio 1: \n");
    concat(lst, lst2, lstCon);
    printf("Listas Concatenadas: \n");
    display(lstCon);

    printf("Exercicio 2: \n");

    printf("Exercicio 3: \n");
    num = 9;
    vectToList(num, vet, lstVect);
    display(lstVect);

    printf("Exercicio 4: \n");
    intercala(lst, lst2, lstIntercal);
    display(lstIntercal);
}

void inserir(int num, int content, cel *lst)
{
    if(num > 0)
    {
        printf("insira o conteudo da celula da primeira lista: ");
        scanf("%d", &content);
        cel *noval;
        noval = malloc(sizeof(cel));
        noval->cont = content;
        noval->next = lst->next;
        lst->next = noval;
        inserir(num-1, content, lst);
    }
    else
        return lst;
}

void inserir2(int num, int content, cel *lst)
{
    if(num > 0)
    {
        printf("insira o conteudo da celula da segunda lista: ");
        scanf("%d", &content);
        cel *noval;
        noval = malloc(sizeof(cel));
        noval->cont = content;
        noval->next = lst->next;
        lst->next = noval;
        inserir2(num-1, content, lst);
    }
    else
        return lst;
}

void display(cel *con)
{
    if (con->next != NULL)
    {
        printf("%d, ", con->cont);
        display(con->next);
    }
    printf("\n");
}

void concat(cel *lst, cel *lst2, cel *con)
{
    if(lst != NULL)
    {
        cel *nova;
        nova = malloc (sizeof (cel));
        nova->cont = lst->cont;
        nova->next = con->next;
        con->next = nova;

        concat(lst->next, lst2, con);
    }
    else if(lst2 != NULL)
    {
        cel *nova2;
        nova2 = malloc (sizeof (cel));
        nova2->cont = lst2->cont;
        nova2->next = con->next;
        con->next = nova2;

        concat(lst, lst2->next, con);
    }
    return;
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

void intercala(cel *lst, cel *lst2, cel *con)
{
    if(lst != NULL && lst2 != NULL)
    {
        cel *nova;
        nova = malloc (sizeof (cel));
        nova->cont = lst->cont;
        nova->next = con->next;
        con->next = nova;

        cel *nova2;
        nova2 = malloc (sizeof (cel));
        nova2->cont = lst2->cont;
        nova2->next = con->next;
        con->next = nova2;

        intercala(lst->next, lst2->next, con);
    }
    return;
}
