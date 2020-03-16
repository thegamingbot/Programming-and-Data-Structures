#include<stdio.h>

#include<stdlib.h>

struct node
{
	int data;
	struct node *nptr;
};

struct node *hptr1;

struct node *hptr2 = NULL;

void insert2 (int x,int pos);

struct node* CopyList(struct node* hptr2);

void reverse(); 

void print();

int main()
{
	insert2 (2,0);	
	insert2 (20,1);
	insert2 (10,1);
	insert2 (12,3);
	insert2 (23,1);
	hptr1 = CopyList(hptr2);
	reverse ();
	print ();
	return 0;
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

struct node* CopyList(struct node* hptr2)
{
	if (hptr2 == NULL)
		return NULL;
	else 
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = hptr2->data;
		temp->nptr = CopyList(hptr2->nptr);
		return temp;
	}
}

void reverse() 
{ 
    struct node* prev = NULL; 
    struct node* current = hptr1; 
    struct node* next = NULL; 
    while (current != NULL)
	{
        next = current->nptr; 
        current->nptr = prev; 
        prev = current; 
        current = next; 
    } 
    hptr1 = prev; 
}

void print()
{
	struct node *thptr2 = hptr2;
	while(thptr2 != NULL)
	{
		printf("%d\t",thptr2->data);
		thptr2 = thptr2->nptr;
	}
	printf("\n");
	struct node *thptr1 = hptr1;
	while(thptr1 != NULL)
	{
		printf("%d\t",thptr1->data);
		thptr1 = thptr1->nptr;
	}
}
