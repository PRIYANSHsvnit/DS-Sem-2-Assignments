#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* createnode(int key)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = key;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* createBT(int pre[],int lpre,int hpre,int in[],int lin,int hin)
{
    if (lpre > hpre || lin > hin) {
        return NULL;
    }

    node* root = createnode(pre[lpre]);
    int i;

    for(i=lin;i<=hin;i++)
    {
        if(pre[lpre] == in[i]) break;
    }

    int size = i-lin;
    root->left = createBT(pre,lpre+1,lpre+size,in,lin,lin+size-1);
    root->right = createBT(pre,lpre+size+1,hpre,in,lin+size+1,hin);

    return root;
}

void display(node* root, int level)
{
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%d\n", root->data);

    display(root->left, level + 1);
    display(root->right, level + 1);
}

int main()
{
    int n,m;

    printf("Enter Size of Preorder = \n");
    scanf("%d",&n);

    printf("\nEnter Size of Inorder = \n");
    scanf("%d",&m);

    int pre[n];
    int in[m];

    printf("\nEnter Preorder = \n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&pre[i]);
    }

    printf("\nEnter Inorder = \n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }

    int x = sizeof(pre) / sizeof(pre[0]);

    node* root = createBT(pre,0,x-1,in,0,n-1);

    printf("\nDisplaying Created Tree...\n");

    display(root,0);
}