#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

void reverse(struct Node *ptr)
{

    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->prev;
    }
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
    head->prev = NULL;

    second->data = 11;
    second->next = third;
    second->prev = head;

    third->data = 41;
    third->next = fourth;
    third->prev = second;

    fourth->data = 88;
    fourth->next = NULL;
    fourth->prev = third;

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
    // head = reverselist(head);
    printf("after insertion\n");
    linkedlistTraversal(head);
    // reverse(fourth);

    return 0;
}