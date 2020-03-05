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
    int num;
    int num2;
    printf("insira quantas celulas deseja criar na primeira lista: ");
    scanf("%d", &num);
    printf("insira quantas celulas deseja criar na segunda lista: ");
    scanf("%d", &num2);
    cel *lst;
    cel *lst2;
    cel *lstCon;
    lst = malloc(sizeof(cel));
    lst->cont = NULL;
    lst->next = NULL;
    lst2 = malloc(sizeof(cel));
    lst2->cont = NULL;
    lst2->next = NULL;
    lstCon = malloc(sizeof(cel));
    lstCon->cont = NULL;
    lstCon->next = NULL;
    inserir(num, n, lst);
    inserir2(num2, n, lst2);
    printf("Primeira lista: \n");
    display(lst);
    printf("Segunda lista: \n");
    display(lst2);
    printf("Listas Concatenadas: \n");
    concat(lst, lst2, lstCon);
    display(lstCon);


}
void display(cel *con)
{
    if (con != NULL)
    {
        printf("%d, ", con->cont);
        display(con->next);
    }
    printf("\n");
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

void concat(cel *lst, cel *lst2, cel *con)
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

        concat(lst->next, lst2->next, con);
    }
    return;
}
