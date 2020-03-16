#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node{
	char data;
	struct node* nptr;
};

struct node* hptr1 = NULL;

void insert1 (char x, int pos);

void print ();

int main()
{
	int a;
	char c[100];
	printf ("Enter the first number:\n");
	scanf("%s", &c);
	a = strlen (c);
	for (int i=a-1; i>=0; i--)
	{
		insert1 (c[i], 0);
	}
	printf ("The number is: ");
	print();
	return 0;
}

void insert1 (char x, int pos)
{
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	temp->data = x;
	struct node* thptr = hptr1;
	temp->nptr = hptr1;
	hptr1 = temp;
}

void print ()
{
	struct node* thptr1 = hptr1;
	while (thptr1 != NULL)
	{
		printf("%c", thptr1->data);
		thptr1 = thptr1->nptr;
	}
	printf("\n");
}
