#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertatfirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct Node * insertatindex(struct Node * head, int data, int index)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i =0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct Node * insertatend(struct Node * head, int data )
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next =NULL;
    return head;

}

struct Node * insertafternode(struct Node * head, struct Node * prevnode, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

struct Node * deletefirstnode(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteatindex(struct Node * head, int index)
{
    struct Node * p = head;
    struct Node * q = p->next;
    for (int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;

    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteatend(struct Node * head)
{
    struct Node * p=head;
    struct Node * q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteatvalue(struct Node * head, int value)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    if(q->data == value)
    {
        p->next=q->next;
        free(q);
        
    }
    return head;
}

struct Node * swapnode(struct Node  * head,int index)
{
    struct Node *p=head;
    struct Node *q;
    struct Node *r;
    int i=1;
    while(i<index-1)
    {
        p=p->next;
        i++;
    }  
    q=p->next;
    r=q->next;

    q->next = r->next;
    r->next = q;
    p->next = r;

    return head;
}

struct Node * reverselist(struct    Node * head)
{
    int count =0;
    struct Node * temp;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    int i,j,k;
    struct Node * p,*q;
    i=0;
    j=count-1;
    p=head;
    q=head;
    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->next;
            k++;
        }
        
        int var = p->data;
        p->data = q->data;
        q->data = var;
        i++;
        j--;
        p = p->next;
        q = head;
    }
    return head;

}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = NULL;

    printf("before insertion\n");
    linkedlistTraversal(head);
    // head = insertatfirst(head,45);
    // head = insertatindex(head,25,1);
    // head = insertatend(head,99);
    // head = insertafternode(head,third,63);
    // head = deletefirstnode(head);
    // head = deleteatindex(head,2);
    // head = deleteatend(head);
    //head = deleteatvalue(head,11);
    // head = swapnode(head,3);
    head = reverselist(head);
    printf("after insertion\n");
    linkedlistTraversal(head);

    return 0;
}
