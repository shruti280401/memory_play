//NOTE : fastest algorithm with time complexity O(n) but takes more space.

#include<stdio.h>
#include<stdlib.h>

void printarr(int *a, int n)
{
    for(int i=0 ; i<n ;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int maximum(int *a, int n)
{
    int max = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
    }
    return max;
}

void countsort(int *a, int n)
{
    int i,j;
    int max = maximum(a,n);
    int* count = (int*)malloc((max+1)*sizeof(int));
    for(i=0 ; i<=max ; i++)
    {
        count[i] = 0;
    }

    for(i=0 ; i<n ; i++)
    {
        count[a[i]]++;
    }

    i =0; //counter for count array
    j=0;  // counter for given array

    while(i<=max)
    {
        if(count[i]>0)
        {
            a[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
        
    }
}

int main()
{
    int a[] = {9,1,4,14,4,15,6};
    int n=7;
    printarr(a,n);
    countsort(a,n);
    printarr(a,n);
}