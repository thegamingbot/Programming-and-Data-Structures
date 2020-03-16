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
void union1();
int isPresent (struct node *ptr, int key);
void print(struct node* ptr);

int main()
{
	int m, n, x;
	printf("Enter the number of elements of the two sets\n");
	scanf("%d %d", &m, &n);
	int a[100], b[100];
	printf("Enter the elements of first set: \n");
	for(int i=0; i<m; i++)
	{
		printf("Enter a number\n");
		scanf("%d", &a[i]);
	}
	printf("Enter the elements of second set: \n");
	for(int i=0; i<n; i++)
	{
		printf("Enter a number\n");
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < m; i++)
		insert(&hptr1, a[i], 0);
	for(int i = 0; i < n; i++)
		insert(&hptr2, b[i], 0);
	union1();
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

void union1()
{
	struct node* thptr1 = hptr1;
	struct node* thptr2 = hptr2;
	struct node* thptr3;
	int i;
	while(thptr1 != NULL)
	{
		insert(&hptr3, thptr1->data, 0);
		thptr1 = thptr1->nptr;
	}
	while(thptr2 != NULL)
	{
		if(!isPresent(hptr3, thptr2->data))
			insert(&hptr3, thptr2->data, 0);
		thptr2 = thptr2->nptr;
	}
}

int isPresent (struct node *ptr, int key) 
{ 
    struct node *thptr = ptr; 
    while (thptr != NULL) 
    { 
        if (thptr->data == key) 
            return 1; 
        thptr = thptr->nptr; 
    } 
    return 0; 
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
