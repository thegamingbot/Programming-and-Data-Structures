#include<stdio.h>

#include<stdlib.h>

struct node
{
	int data;
	struct node *nptr;
};

struct node *hptr1 = NULL;

struct node *hptr = NULL;

void insert1 (int x,int pos);

void insert2 (int x,int pos);

void print();

int main()
{
	insert1 (3,0);
	insert1 (4,0);
	insert1 (9,1);
	insert1 (20,2);
	insert1 (0,0);
	insert2 (2,0);	
	insert2 (20,1);
	insert2 (10,1);
	insert2 (12,3);
	insert2 (23,1);
	print();
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
	struct node *thptr = hptr;
	temp->data = x;
	if(pos == 0)
	{	
		temp->nptr = hptr;
		hptr = temp;	
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

void print()
{
	struct node *thptr1 = hptr1;
	while(thptr1 != NULL)
	{
		printf("%d\t",thptr1->data);
		thptr1 = thptr1->nptr;
	}
	printf("\n");
	struct node *thptr = hptr;
	while(thptr != NULL)
	{
		printf("%d\t",thptr->data);
		thptr = thptr->nptr;
	}
}
