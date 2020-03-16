#include <stdio.h>
#include<stdlib.h>

struct node { 
	int data; 
	struct node* left;
	struct node* right; 
}; 

struct node* root = NULL;

struct node* birth(int data); 
int search(int arr[], int strt, int end, int value);
struct node* build(int inorder[], int postorder[], int inorder_front, int inorder_end, int* postorder_index);
struct node* buildTree(int inorder[], int postorder[], int n);
void preOrder(struct node* root);

int main() 
{ 
	int n;
	printf("Enter the number of nodes:  ");
	scanf("%d", &n);
	int inorder[n];
	int postorder[n];
	printf("Enter the inorder traversal:\n");
	for(int i = 0; i < n; i++)
	{
		printf("Enter the value of node%d:  ", i+1);
		scanf("%d", &inorder[i]);
	}
	printf("Enter the postorder traversal:\n");
	for(int i = 0; i < n; i++)
	{
		printf("Enter the value of node%d:  ", i+1);
		scanf("%d", &postorder[i]);
	}

	int postorder_index = n - 1; 
	root = build(inorder, postorder, 0, n - 1, &postorder_index); 
	
	printf("The pre ordered traversal of the tree is: ");
	preOrder(root); 
	
	return 0; 
} 

struct node* build(int inorder[], int postorder[], int inorder_front, int inorder_end, int* postorder_index) 
{ 
	if (inorder_front > inorder_end) 
	{
		return NULL; 
	}
	
	struct node* temp = birth(postorder[*postorder_index]);
	(*postorder_index)--;
	
	if (inorder_front == inorder_end)
	{
		return temp;
	}
	int inorder_index = search(inorder, inorder_front, inorder_end, temp->data);
	
	temp->right = build(inorder, postorder, inorder_index + 1, inorder_end, postorder_index); 
	temp->left = build(inorder, postorder, inorder_front, inorder_index - 1, postorder_index); 
	
	return temp; 
}

int search(int array[], int front, int end, int value) 
{ 
	int i; 
	for (i = front; i <= end; i++)
	{ 
		if (array[i] == value) 
		{
			break;
		} 
	}
	
	return i; 
} 

struct node* birth(int data) 
{ 
	struct node* temp = (struct node*) malloc(sizeof(struct node)); 
	temp->data = data; 
	temp->left = NULL;
	temp->right = NULL; 
	return (temp); 
} 

void preOrder(struct node* root) 
{
	struct node* troot = root;
	if (troot != NULL) 
	{
		printf("%d ", troot->data); 
		preOrder(troot->left); 
		preOrder(troot->right); 
	}
}
