#include<stdio.h>
#include<stdlib.h>

void printarr(int *arr, int n)
{
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    
}

void insertionsort(int *arr, int n)
{
    int i,j,key;
    for (i=1 ; i<= n-1 ;i++)
    {
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {1,66,43,90,57,9};
    // int arr[] = {1,2,3,4,5};
    int size = 6;
    printarr(arr,size);
    insertionsort(arr,size);
    printarr(arr,size);
}