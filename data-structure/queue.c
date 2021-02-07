#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};


int isEmpty(struct queue*q)
{
    if(q->f == q->r)
    {
        return 1;
    }
    return 0;
}




int isFull(struct queue*q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue*q,int val)
{
    if(isFull(q)){
        printf("This queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
        printf("enqued element: %d\n",val);
    }
    
}

int dequeue(struct queue*q)
{
    int a=-1;    
    if(isEmpty(q))
    {
        return 1;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void traversal(struct queue*q)
{
    if(isEmpty(q))
    {
        printf("No elements in queue\n");
    }
    else
    {
        int i;
        while(q->r!=q->size-1)
        {
            printf("%d\n",q->arr[q->r]);
            q->r++;
        }
    }
    
}

int main()
{
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    // traversal(&q);
    enqueue(&q,5);
    enqueue(&q,8);
    enqueue(&q,11);
    enqueue(&q,22);
    printf("dequing element %d\n",dequeue(&q));
    printf("dequing element %d\n",dequeue(&q));
    printf("dequing element %d\n",dequeue(&q));
    traversal(&q);

}