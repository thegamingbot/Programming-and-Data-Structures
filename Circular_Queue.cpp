#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct CircularArray{
	int a[10];
	int f;
	int r;
};

void enqueue (struct CircularArray *pc1, int x);

void dequeue (struct CircularArray *pc1);

int IsFull (struct CircularArray *pc1);

int IsEmpty (struct CircularArray *pc1);

void print (struct CircularArray *pc1);

int main()
{
	struct CircularArray c1, *pc1;
	pc1 = &c1;
	pc1->f = -1;
	pc1->r = -1;
	enqueue (pc1, 10);
	enqueue (pc1, 9);
	enqueue (pc1, 8);
	enqueue (pc1, 7);
	enqueue (pc1, 6);
	enqueue (pc1, 5);
	enqueue (pc1, 4);
	enqueue (pc1, 3);
	enqueue (pc1, 2);
	enqueue (pc1, 1);
	print (pc1);
	printf ("\n");
	if (IsFull(pc1)==0)
		printf("The queue is not full\n");
	else
		printf("The queue is full\n");
	dequeue (pc1);
	dequeue (pc1);
	dequeue (pc1);
	dequeue (pc1);
	print (pc1);
	printf ("\n");
	enqueue (pc1, 10);
	enqueue (pc1, 9);
	enqueue (pc1, 8);
	print (pc1);
	printf ("\n");
	if (IsEmpty(pc1)==0)
		printf("The queue is not empty\n");
	else
		printf("The queue is empty\n");
}

void enqueue (struct CircularArray *pc1, int x)
{
	if (pc1->f == -1)
		pc1->f = 0;
	pc1->r = (pc1->r + 1) % (sizeof(pc1->a)/4);
	pc1->a[pc1->r] = x;
}

void dequeue (struct CircularArray *pc1)
{
	pc1->a[pc1->f] = 0;
	pc1->f = (pc1->f + 1) % (sizeof(pc1->a)/4);
}

int IsFull (struct CircularArray *pc1)
{
	if ((pc1->f == pc1->r + 1) || (pc1->f == 0 && pc1->r == (sizeof(pc1->a)/4)-1))
		return 1;
	else 
		return 0; 
}

int IsEmpty (struct CircularArray *pc1)
{
	if (pc1->f == -1)
		return 1;
	else 
		return 0; 
}

void print (struct CircularArray *pc1)
{
	int i;
	for (i = pc1->f; i != pc1->r; i = (i+1) % (sizeof(pc1->a)/4))
	{
		printf ("%d\t", pc1->a[i]);
	}
	printf ("%d", pc1->a[i]);
}
