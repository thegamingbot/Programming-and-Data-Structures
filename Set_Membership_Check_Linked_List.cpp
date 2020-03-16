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
int isPresent (struct node *ptr, int key);

int main()
{
	int m, n, key;
	printf("Enter the number of elements of the two sets\n");
	scanf("%d", &m);
	int a[100];
	printf("Enter the elements of first set: \n");
	for(int i=0; i<m; i++)
	{
		printf("Enter a number\n");
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++)
		insert(&hptr1, a[i], 0);
	printf("Enter the search element: ");
	scanf("%d", &key);
	n = isPresent(hptr1, key);
	if(n)
		printf("%d is present in the list\n", key);
	else
		printf("%d is not present in the list\n", key);
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
