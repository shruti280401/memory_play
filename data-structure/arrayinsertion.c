#include<stdio.h>
#include<conio.h>

void display(int arr[],int n)
{
    //traversal
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indinsertion(int arr[],int size, int element ,int capacity ,int index)
{
    //basic insertion
    if(size>=capacity)
    {
        return -1;
    }
    else
    {
        for (int i=size-1;i>=index;i--)
        {
            arr[i+1]=arr[i];

        }
        arr[index]=element;
        return 1;
    }   
}



void indeletion(int arr[],int size ,int capacity ,int index)
{
    //basic deletion
    if(index>=capacity)
    {
        printf("not possible");
    }
    else
    {
        for (int i=index; i<size; i++)
        {
            arr[i]=arr[i+1];

        }
    }   
}

int main()
{
    int arr[100] = {7,8,12,27,88};
    int size = 4, element = 36, index=3,capacity =100;
    display(arr,size);
    indinsertion(arr,size, element ,capacity ,index);
    size+=1;
    display(arr,size);
    indeletion(arr,size,capacity,index);
    size-=1;
    display(arr,size);
    return 0;
}
