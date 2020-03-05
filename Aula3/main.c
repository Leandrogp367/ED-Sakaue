#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int content;
    struct linkedList *next;
}cel;

int main()
{
    int count = 0;
    cel *con;
    con = malloc(sizeof(cel));
    cel *cabeca;
    cabeca = malloc(sizeof(cel));
    cabeca->next = NULL;
    con->next = cabeca;

    cel *a;
    cel *b;
    cel *c;
    cel *ll;
    a = malloc(sizeof(cel));
    b = malloc(sizeof(cel));
    c = malloc(sizeof(cel));
    ll = malloc(sizeof(cel));

    a->content = 10;
    a->next = b;
    b->content = 11;
    b->next = c;
    c->content = 12;
    c->next = ll;
    ll->content = 13;
    ll->next = NULL;

    cel *d;
    cel *f;
    cel *g;
    cel *ca;
    d = malloc(sizeof(cel));
    f = malloc(sizeof(cel));
    g = malloc(sizeof(cel));
    ca = malloc(sizeof(cel));

    d->content = 20;
    d->next = f;
    f->content = 21;
    f->next = g;
    g->content = 22;
    g->next = ca;
    ca->content = 23;
    ca->next = NULL;

    printf("lista Encadeada 1: \n");
    displayList(a);
    printf("Lista Encadeada 2: \n");
    displayList2(d);
    concatena(a, d, con);
    printf("Listas Concatenadas: \n");
    displayConcatenacao(con);

    cel *p;
    for (p = a->next; p != NULL; p = p->next)
    {
        remotion(p->content, d);
    }
}

void displayList(cel *ll)
{
    if(ll != NULL)
    {
        printf("%d, ", ll->content);
        displayList(ll->next);
    }
    printf("\n");
}

void displayList2(cel *ll)
{
    if(ll != NULL)
    {
        printf("%d, ", ll->content);
        displayList(ll->next);
    }
    printf("\n");
}

void displayConcatenacao(cel *con)
{
    if (con != NULL)
    {
        printf("%d, ", con->content);
        displayConcatenacao(con->next);
    }
    printf("\n");
}

void concatena(cel *ll1, cel *ll2, cel *con)
{
    if(ll1 != NULL && ll2 != NULL)
    {
        cel *nova;
        nova = malloc (sizeof (cel));
        nova->content = ll1->content;
        nova->next = con->next;
        con->next = nova;

        cel *nova2;
        nova2 = malloc (sizeof (cel));
        nova2->content = ll2->content;
        nova2->next = con->next;
        con->next = nova2;

        concatena(ll1->next, ll2->next, con);
    }
    return;
}

void remotion (int y, cel *le)
{
   cel *p, *q;
   p = le;
   q = le->next;
   while (q != NULL && q->content != y)
   {
      p = q;
      q = q->next;
   }
   if (q != NULL)
   {
      p->next = q->next;
      free (q);
   }
}
