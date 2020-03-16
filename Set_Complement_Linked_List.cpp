#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* nptr;
};

struct node* hptr1 = NULL;
struct node* hptr2 = NULL;
struct node* hptr3 = NULL;

void insert(struct node** ptr, int x, int pos);
void comp();
void print(struct node* ptr);

int main()
{
	int m, n, x;
	printf("Enter the number of elements of the two sets\n");
	scanf("%d %d", &m, &n);
	int a[100], b[100];
	printf("Enter the elements of universal set: \n");
	for(int i=0; i<m; i++)
	{
		printf("Enter a number\n");
		scanf("%d", &a[i]);
	}
	printf("Enter the elements of set: \n");
	for(int i=0; i<n; i++)
	{
		printf("Enter a number\n");
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < m; i++)
		insert(&hptr1, a[i], 0);
	for(int i = 0; i < n; i++)
		insert(&hptr2, b[i], 0);
	comp();
	printf("{ ");
	print(hptr3);
	printf("\b\b }");
}

void insert(struct node** ptr, int x, int pos)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	struct node* thptr = *ptr;
	temp->data = x;
	if(pos == 0)
	{
		temp->nptr = *ptr;
		*ptr = temp;
	}
	else
	{
		int i = 0;
		while(i<pos-1)
		{
			thptr = thptr->nptr;
			i++;
		}
		temp->nptr = thptr->nptr;
		thptr->nptr = temp;
	}
}

void comp()
{
	struct node* thptr1 = hptr1;
	struct node* thptr2 = hptr2;
	struct node* thptr3;
	while(thptr1 != NULL)
	{
		thptr2 = hptr2;
		while(thptr2 != NULL)
		{
			if(thptr1->data != thptr2->data)
			{
				insert(&hptr3, thptr1->data, 0);
			}
			thptr2 = thptr2->nptr;
		}
		thptr1 = thptr1->nptr;
	}
}

void print(struct node* ptr)
{
	struct node* thptr = ptr;
	while(thptr != NULL)
	{
		printf("%d, ", thptr->data);
		thptr = thptr->nptr;
	}
}
