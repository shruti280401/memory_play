#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


void linkedlistTraversal(struct Node *head)
{
    struct Node * ptr = head;

    do
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}


struct Node * insertatfirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next != head){
        p=p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    fourth->next = head;

    printf("before insertion\n");
    linkedlistTraversal(head);
    head = insertatfirst(head,1);
    printf("after insertion\n");
    linkedlistTraversal(head);
    return 0;
}    