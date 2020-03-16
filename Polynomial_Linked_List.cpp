#include <stdio.h>

#include <stdlib.h>
 
#include <math.h>

struct node
{
	int data;
	struct node *nptr;
};

struct node *hptr1 = NULL;

struct node *hptr2 = NULL;

void insert1 (int x,int pos);

void insert2 (int x,int pos);

int Simplify();

int main()
{
	int b, y, value, m[100];
	printf("Enter the highest power of the polynomial\n");
	scanf("%d", &b);
	for(int i = b; i>=0; i--)
	{
		printf("Enter the coefficient of x^%d :\t", i);
		scanf("%d", &m[i]);
	}
	for(int i = b; i>=0; i--)
	{
		insert1 (m[i], 0);
	}
	printf("Enter the value of x: \t");
	scanf("%d", &y);
	for(int i = b; i>=0; i--)
	{
		insert2 (pow(y, i), 0);
	}
	value = Simplify();
	printf("The value of the polynomial at x = %d is %d\n", y, value);
	return 0;
}

void insert1(int x, int pos)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	int i = 0;
	struct node *thptr = hptr1;
	temp->data = x;
	if(pos == 0)
	{	
		temp->nptr = hptr1;
		hptr1 = temp;	
	}	
	else
	{
		while(i < pos-1)	
		{		
			thptr = thptr->nptr;
			i++;
		}
		temp->nptr = thptr->nptr;
		thptr->nptr = temp;
	}
}

void insert2(int x, int pos)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	int i = 0;
	struct node *thptr = hptr2;
	temp->data = x;
	if(pos == 0)
	{	
		temp->nptr = hptr2;
		hptr2 = temp;	
	}	
	else
	{
		while(i < pos-1)	
		{		
			thptr = thptr->nptr;
			i++;
		}
		temp->nptr = thptr->nptr;
		thptr->nptr = temp;
	}
}

int Simplify()
{
	int sum = 0;
	struct node *thptr1 = hptr1;
	struct node *thptr2 = hptr2;
	while(thptr1 != NULL && thptr2 != NULL)
	{
		sum = sum + (thptr1->data * thptr2->data);
		thptr1 = thptr1->nptr;
		thptr2 = thptr2->nptr;
	}
	return sum;
}
