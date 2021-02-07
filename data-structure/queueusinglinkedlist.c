#include<stdio.h>
#include<stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node* next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if(n == NULL)
    {
        printf("queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if(f == NULL)
        {
            f=r=n;
        }
        else
        {
            r->next = n;
            r=n;
            printf("enqueued element %d\n",val);
           
        }   
    }   
}

int dequeue()
{
    int val = -1;
    struct Node* ptr = f;
    if(f==NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;    
}

int main()
{
    linkedlistTraversal(f);
    enqueue(34);
    enqueue(9);
    enqueue(88);
    enqueue(7);
    // printf("dequeuing element %d\n",dequeue());
    printf("dequeuing element %d\n",dequeue());
    printf("dequeuing element %d\n",dequeue());
    printf("dequeuing element %d\n",dequeue());
    linkedlistTraversal(f);
    return 0;
}