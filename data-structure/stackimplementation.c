#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
void push(int);
int pop();
int isFull();
int isEmpty();
void traverse();
void peek();
int stack[CAPACITY],top=-1;
void push(int ele)
{
	if(isFull())
	{
		printf("stack is overflow\n");

	}
	else
	{
		top++;
		stack[top]=ele;
		printf("%d pushed successfully\n",ele);
	}
}
isFull()
{
	if(top==CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pop()
{
	if(isEmpty())
	{
		printf("stack is underflow\n");
	}
	else
	{
		top--   ;
	}
}
isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void peek()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("peek ele is %d\n",stack[top]);
	}
}
void traverse()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
	}
	else
	{
		int i;
		printf("stack elements:\n");
		for(i=0;i<=top;i++)
		{
			printf("%d\n",stack[i]);
		}
	}
}
int main()
{
	int ch,item;
	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.traverse\n");
		printf("5.exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:printf("Enter element to push:");
			       scanf("%d",&item);
			       push(item);
			       break;
			case 2:item=pop();
			       if(item==0)
			       {
					printf("stack is underflow\n");
			       }
			       else
			       {
					printf("pop item  is %d\n",item);
			       }
			       break;
				case 3:peek();
				break;
				case 4:traverse();
				break;
				case 5:exit(0);
				default:printf("Invalid input\n")    ;

		}
		return 0;
	}
}
