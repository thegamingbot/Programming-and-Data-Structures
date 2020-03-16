#include<stdio.h> 
#include<stdlib.h> 

struct root 
{ 
	int key; 
	struct root *left, *right;
	int height; 
};

struct root *newroot(int item);
void inorder(struct root *root);
struct root* insert(struct root* root, int key);
struct root * minValueroot(struct root* root);
struct root* deleteroot(struct root* root, int key);
struct root* RR(struct root* x);
struct root* LR(struct root* x);
int BF(struct root* root);
int max(int a, int b);
int height(struct root* root);

int main() 
{
	struct root *root = NULL; 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50);
	printf("Inorder traversal of the tree \n"); 
	inorder(root); 

	root = deleteroot(root, 20); 
	printf("\nInorder traversal of the modified tree \n"); 
	inorder(root); 
	root = deleteroot(root, 30); 
	printf("\nInorder traversal of the modified tree \n"); 
	inorder(root); 
	root = deleteroot(root, 50); 
	printf("\nInorder traversal of the modified tree \n"); 
	inorder(root); 

	return 0; 
} 

struct root *newroot(int item) 
{ 
	struct root *temp = (struct root *)malloc(sizeof(struct root)); 
	temp->key = item; 
	temp->left = temp->right = NULL;
	temp->height = 0;
	return temp; 
} 

void inorder(struct root *root) 
{ 
	if (root != NULL) 
	{ 
		printf("%d ", root->key); 
		inorder(root->left); 
		inorder(root->right); 
	} 
} 

struct root* insert(struct root* root, int key) 
{ 
	if (root == NULL) return newroot(key); 

	if (key < root->key) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	
	int bal_factor = BF(root);
    
    if (bal_factor > 1 && key < root->left->key) 
    {
	    return RR(root);
	}
	else if (bal_factor < -1 && key > root->right->key) 
    {
		return LR(root);
    }
    else if (bal_factor > 1 && key > root->left->key) 
    { 
        root->left =  LR(root->left); 
        return RR(root); 
    }
    else if (bal_factor < -1 && key < root->right->key) 
    { 
        root->right = RR(root->right); 
        return LR(root); 
    }	
	
	return root; 
} 

struct root * minValueroot(struct root* root) 
{ 
	struct root* current = root; 

	while (current && current->left != NULL) 
		current = current->left; 

	return current; 
} 

struct root* deleteroot(struct root* root, int key) 
{ 
	if (root == NULL) return root; 

	if (key < root->key) 
		root->left = deleteroot(root->left, key); 

	else if (key > root->key) 
		root->right = deleteroot(root->right, key); 

	else
	{ 
		if (root->left == NULL) 
		{ 
			struct root *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct root *temp = root->left; 
			free(root); 
			return temp; 
		} 

		struct root* temp = minValueroot(root->right); 

		root->key = temp->key; 

		root->right = deleteroot(root->right, temp->key); 
	}
	
	int bal_factor = BF(root);
    
    if (bal_factor > 1 && key < root->left->key) 
    {
	    return RR(root);
	}
	else if (bal_factor < -1 && key > root->right->key) 
    {
		return LR(root);
    }
    else if (bal_factor > 1 && key > root->left->key) 
    { 
        root->left =  LR(root->left); 
        return RR(root); 
    }
    else if (bal_factor < -1 && key < root->right->key) 
    { 
        root->right = RR(root->right); 
        return LR(root); 
    }
	
	return root; 
}

int height(struct root* root)  
{  
    if (root == NULL)  
        return 0;
    else
    {
        int lh = height(root->left);  
        int rh = height(root->right);
        if (lh > rh)  
            return(lh + 1);  
        else 
			return(rh + 1);  
    }  
}

int max(int a, int b)
{
	if(a < b)
		return b;
	else 
		return a;
}

int BF(struct root* root)
{
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

struct root* RR(struct root* x) 
{ 
    struct root *y = x->left; 
    struct root *z = y->right; 
    
    y->right = x; 
    x->left = z; 

    x->height = 1 + max(height(x->left), height(x->right)); 
    y->height = 1 + max(height(y->left), height(y->right)); 

    return y; 
} 

struct root* LR(struct root* x) 
{ 
    struct root *y = x->right; 
    struct root *z = y->left; 
    
    y->left = x; 
    x->right = z; 

    x->height = 1 + max(height(x->left), height(x->right)); 
    y->height = 1 + max(height(y->left), height(y->right)); 

    return y; 
} 
