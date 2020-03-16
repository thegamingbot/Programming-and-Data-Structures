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

void enqueue (int x);
void dequeue ();
int IsFull ();
int IsEmpty ();
void print ();

int main ()
{
    if (IsEmpty()==0)
		printf("The queue is not empty\n");
	else
		printf("The queue is empty\n");
	enqueue (2);
    enqueue (20);
    enqueue (10);
    enqueue (12);
    enqueue (23);
    print ();
    printf("\n");
    dequeue ();
    dequeue ();
    dequeue ();
    print ();
    printf("\n");
    if (IsFull()==0)
		printf("The queue is not full\n");
	else
		printf("The queue is full\n");
	return 0;
}

void enqueue (int x)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = x;
    if (hptr == NULL)
    {
        temp->nptr = temp;
        rear = temp;
        hptr = temp;
        front = temp;
    }
    else
    {
        rear->nptr = temp;
        temp->nptr = hptr;
        rear = temp;
    }
}

void dequeue ()
{
	front = front->nptr;
	hptr = hptr->nptr;
	rear->nptr = hptr;
}

int IsFull ()
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	if (temp == NULL)
		return 1;
	else 
		return 0; 
}

int IsEmpty ()
{
	if (hptr == NULL)
		return 1;
	else 
		return 0; 
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
