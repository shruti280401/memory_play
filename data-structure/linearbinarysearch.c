#include<stdio.h>

int linearsearch(int arr[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[],int size,int element)
{
    int low,high,mid;
    low=0;
    high=size-1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low = mid+1;
        }
        else
        {
            {
                high = mid-1;
            }
        }    
    }
    return -1;
}

int main()
{
    // int arr[]={1,4,66,32,890,44,789,12,34,56,78,0};
    int arr[] = {1,23,45,67,89,123,900};
    int size = sizeof(arr)/sizeof(int);
    int ele=32;
    int searchindex = linearsearch(arr, size, ele);
    printf("the element %d was found at index %d\n",ele,searchindex);
    int search = binarysearch(arr , size, ele);
    printf("the element %d was found at index %d\n",ele,search);
    return 0;
}