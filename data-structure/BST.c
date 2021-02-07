#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node* root){
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL)
    {
        
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node* root){
    if(root!=NULL)
    {
        
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        
    }
}

int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && prev->data>=root->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);    
    }
    else
    {
        return 1;
    }
    
}
//recuersive method
struct node* search(struct node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        return root;
    }
    else if(root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
    
}

struct node* searchiter(struct node* root, int key)
{
    while(root!=NULL)
    {
        if(key == root->data)
        {
            return root;
        }
        else if(key<root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
        
    }
    return NULL;
    
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(key == root->data)
        {
            printf("cannot insert %d,already in BST",key);
            return;
        }
        else if(key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }    
    }
    struct node* new = createnode(key);
    if(key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
    
}

int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preorder(p);
    // printf("\n");
    // postorder(p);
    // printf("\n");
    // inorder(p);
    // printf("\n");
    // printf("%d ",isBST(p));
    // struct node* n = searchiter(p, 4);
    // if(n!=NULL){
    //     printf("found:%d",n->data);
    // }
    // else
    // {
    //     printf("element not found");
    // } 
    insert(p,2);
    printf("%d",p->right->right->data);
    return 0;
}