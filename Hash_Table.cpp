#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node{
	int data;
	struct node* next;
};

struct node table[size];

void initialize();
int hash(int key);
void insert(int key);
int del(int key);
int search(int key);
void print();

int main()
{
	initialize();
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);
	insert(80);
	insert(90);
	print();
	printf("\n");
	del(40);
	del(70);
	del(90);
	print();
	printf("\n%d\n", search(60));
	printf("%d\n", search(70));
}

void initialize()
{
	for(int i = 0; i < size; i++)
	{
		table[i].data = 0;
		table[i].next = NULL;
	}
}

int hash(int key)
{
	return key / size;
}

void insert(int key)
{
	table[hash(key)].data = 1;
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = key;
	temp->next = table[hash(key)].next;
	table[hash(key)].next = temp;
}

int del(int key)
{
	struct node* temp = table[hash(key)].next;
	struct node* prev;
	
	if(temp->data == key)
	{
		table[hash(key)].next = temp->next;
		free(temp);
		return 1;
	}
	
	while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL)
		return 0;

    prev->next = temp->next; 
	free(temp);
	return 1;
}

int search(int key)
{
	struct node* temp = table[hash(key)].next;
	while (temp != NULL)
	{
		if(temp->data == key)
			return 1;
		temp = temp->next;
	}
	return 0;
}

void print()
{
	struct node* temp;
	for(int i = 0; i < size; i++)
	{
		if(table[i].data == 1)
		{
			temp = table[i].next;
			while(temp != NULL)
			{
				printf("%d\t", temp->data);
				temp = temp->next;
			}
		}
	}
}
