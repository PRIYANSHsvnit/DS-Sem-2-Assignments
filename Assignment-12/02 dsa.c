#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node* createnode(int value)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = value;
    new->left = new->right = NULL;
    return new;
}

node* insert(node* root, int value)
{
    if(root == NULL) return createnode(value);
    
    if(value < root->data) root->left = insert(root->left, value);

    else root->right = insert(root->right, value);

    return root;
}

void inorder(node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void freetree(node* root)
{
    if(root == NULL) return;
    freetree(root->left);
    freetree(root->right);
    free(root);
}

int main()
{
    node* root = NULL;
    int value,n,i;

    printf("Enter How many members you want in tree = \n");
    scanf("%d",&n);

    printf("Enter Members according to Preorder = \n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal = \n");
    inorder(root);

    printf("\nPreorder Traversal = \n");
    preorder(root);

    printf("\nPostorder Traversal = \n");
    postorder(root);

    printf("\n");

    freetree(root);
    return 0;
}