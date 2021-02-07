#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* top = NULL;

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node * top){
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

int isFull(struct Node * top)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node* push(struct Node* top,int x)
{
    if(isFull(top))
    {
        printf("stack overflown\n");
    }
    else
    {
        struct Node * n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
    
}
int pop(struct Node* tp)
{
    if(isEmpty(top))
    {
        printf("stack underflown\n");
    }
    else
    {
        struct Node* n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
    
}

int peek(int pos)
{
    struct Node* ptr = top;
    for(int i=0; (i<pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
    
}

int stacktop()
{
    return top->data;
}

int stackbottom()
{
    struct Node* ptr = top;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
int main()
{
    top = push(top,78);
    top = push(top,7);
    top = push(top,8);
    // linkedlistTraversal(top);

    // int ele = pop(top);
    // printf("popped element is %d\n",ele);
    linkedlistTraversal(top);
    for(int i=1 ; i<=3; i++)
    {
        printf("value at position %d is : %d\n",i,peek(i));
    }
    printf("element at top of stack is %d\n",stacktop());
    printf("element at bottom of stack is %d\n",stackbottom());

    return 0;
}