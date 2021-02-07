#include<stdio.h>
#include<stdlib.h>


struct Array{
    int total_size;
    int used_size;
    int *ptr;
};
void create_array(struct Array* a, int tsize ,int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize*sizeof(int));
}
void show(struct Array *a,int total_size,int used_size)
{
    if(used_size<total_size)
    {
        for(int i=0; i< a->used_size; i++)
        {
            printf("%d\n",(a->ptr)[i]);
        }
    }
    else
    {
        printf("elements going beyond array");
    }
    
}
void setVal(struct Array *a)
{
    int n;
    for(int i=0; i< a->used_size; i++)
    {
        printf("enter elements %d",i);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
}

int main(){

    struct Array marks;
    create_array(&marks, 10, 9);
    setVal(&marks);
    show(&marks,10,11);
    return 0;
}

