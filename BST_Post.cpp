#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

struct node 
{ 
    int data; 
    struct node *left, *right; 
};

struct node* birth (int data);
struct node* insert(struct node* node, int key);
void InOrder (struct node* node);


int main () 
{ 
	int size;
	printf("Enter the number of nodes:  ");
	scanf("%d", &size);
	int postorder[size];
	printf("Enter the postorder traversal:\n");
	for(int i = 0; i < size; i++)
	{
		printf("Enter the value of node%d:  ", i+1);
		scanf("%d", &postorder[i]);
	}

	struct node* root = NULL;
	root = insert(root, postorder[size-1]);
	for(int i = size-2; i >= 0; i--)
		insert(root, postorder[i]);
   
    printf("Inorder traversal of the constructed tree: \n"); 
    InOrder(root); 

    return 0; 
}

struct node* birth (int data) 
{ 
    struct node* temp = (struct node *) malloc( sizeof(struct node)); 

    temp->data = data; 
    temp->left = NULL;
    temp->right = NULL;
    
    return temp; 
} 

struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL)
		return birth(key); 
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    return node;
}

void InOrder (struct node* node) 
{
	struct node* troot = node;
    if (troot == NULL) 
        return; 
    InOrder(troot->left); 
    printf("%d ", troot->data); 
    InOrder(troot->right); 
} 
