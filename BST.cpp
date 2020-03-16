#include<stdio.h>
#include<stdlib.h>

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \t", root->key); 
        inorder(root->right); 
    } 
} 

void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d \t", root->key);
		preorder(root->left); 
        preorder(root->right); 
    } 
} 

void postorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d \t", root->key); 
    } 
} 
   
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);  
    return node;
} 
   
int main() 
{ 
    struct node *root = NULL; 
    root = insert(root, 40); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 80); 
    insert(root, 70);  
   
    inorder(root); 
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
   
    return 0; 
} 
