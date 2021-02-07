#include<stdio.h>
#include<stdlib.h>

void printarr(int *arr, int n)
{
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    
}

void bubblesort(int *arr,int n)
{
    int issorted=0;
    for(int i=0;i<n-1;i++)
    {
        issorted = 1;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                issorted = 0;
            }
        }
        if(issorted){
            return ;
        }
    }
}
int main()
{
    int arr[] = {1,66,43,90,57};
    // int arr[] = {1,2,3,4,5};
    int size = 5;
    printarr(arr,size);
    bubblesort(arr,size);
    printarr(arr,size);
}