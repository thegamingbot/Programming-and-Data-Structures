#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node{
	int data;
	struct node* nptr;
};

struct node* hptr1 = NULL;
struct node* hptr2 = NULL;
struct node* hptr3 = NULL;

void insert1 (int x, int pos);

void insert2 (int x, int pos);

void reverse (struct node* hptr);

int compare();

void print (struct node* hptr);

int main()
{
	int a, b;
	char c[100], d[100];
	printf ("Enter the first number:\n");
	scanf ("%s", &c);
	a = strlen(c);
	printf ("Enter the second number:\n");
	scanf ("%s", &d);
	b = strlen(d);
	for (int i=a-1; i>=0; i--)
		insert1 (c[i], 0);
	for (int i=b-1; i>=0; i--)
		insert2 (d[i], 0);
	if(a>b || compare() == 1)
		printf("The first number is greater");
	else if(b>a || compare() == 2)
		printf("The second number is greater");
	else if(compare() == 0)
		printf("The numbers are equal");
}

void insert1 (int x, int pos)
{
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	temp->data = x;
	temp->nptr = hptr1;
	hptr1 = temp;
}

void insert2 (int x, int pos)
{
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	temp->data = x;
	temp->nptr = hptr2;
	hptr2 = temp;
}

int compare()
{
	struct node* thptr1 = hptr1;
	struct node* thptr2 = hptr2;
	int x = 0;
	while(thptr1 != NULL && thptr2 != NULL)
	{
		if(thptr1->data > thptr2->data)
		{
			x = 1;
			break;
		}
		else if(thptr1->data < thptr2->data)
		{
			x = 2;
			break;
		}
		else
		{
			thptr1 = thptr1->nptr;
			thptr2 = thptr2->nptr;
		}	
	}
	return x;
}
