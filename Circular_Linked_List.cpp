#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nptr;
};

struct node* hptr = NULL;
struct node* rear = NULL;
struct node* front = NULL;

void insert (int x, int pos);
void insert_first (int x);
void insert_last (int x, int pos);
void insert_middle (int x, int pos);
void print ();

int main ()
{
    insert (2,0);
	insert (20,1);
    insert (10,2);
    insert (12,3);
    insert (23,2);
    print ();
    return 0;
}

void insert (int x, int pos)
{
    int size = 0;
    struct node* thptr = hptr;
    if (pos == 0)
        insert_first (x);
    else if (pos != 0)
    {
        while (thptr->nptr != hptr)
        {
            thptr = thptr->nptr;
            size++;
        }
        if (pos == size+1)
            insert_last (x, pos);
        else if (pos > 0 && pos < size+1)
            insert_middle (x, pos);
    }
}

void insert_first (int x)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = x;
    if (hptr == NULL)
    {
        temp->nptr = temp;
        rear = temp;
    }
    else
        temp->nptr = hptr;
    hptr = temp;
    front = temp;
}

void insert_last (int x, int pos)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = x;
    int i=0;
    struct node* thptr = hptr;
    while(i < pos-1)    
    {        
        thptr = thptr->nptr;
        i++;
    }
    thptr->nptr = temp;
    temp->nptr = hptr;
    rear = temp;
}

void insert_middle (int x, int pos)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = x;
    int i=0;
    struct node* thptr = hptr;
    while(i < pos-1)    
    {        
        thptr = thptr->nptr;
        i++;
    }
    temp->nptr = thptr->nptr;
    thptr->nptr = temp;
}

void print()
{
    struct node *thptr = hptr;
    while(thptr->nptr != hptr)
    {
        printf("%d\t",thptr->data);
        thptr = thptr->nptr;
    }
    printf ("%d", thptr->data);
}
