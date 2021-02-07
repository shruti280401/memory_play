#include<stdio.h>
#include<stdlib.h>

void printarr(int *a, int n)
{
    for (int i =0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void selectionsort(int *a , int n)
{
    int temp, indexofmin;
    for (int i =0 ; i<n-1 ; i++)
    {
        indexofmin = i;
        for( int j=i+1 ; j<n ; j++)
        {
            if (a[j]<a[indexofmin])
            {
                indexofmin = j;
            }
        }

        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;

    }

}
int main()
{
    int a[] = {3,5,2,13,12};
    int n =5;
    printarr(a,n);
    selectionsort(a,n);
    printarr(a,n);
    return 0;
    
}