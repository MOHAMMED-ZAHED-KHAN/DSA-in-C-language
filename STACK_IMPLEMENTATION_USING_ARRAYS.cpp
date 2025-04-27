
					//		STACK IMPLEMENTATION USING ARRAYS	


#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int top=-1,stack[CAPACITY];
void push();
void pop();
void peek();
void traverse();
int isFull()
{
	if(top==CAPACITY-1)
	return 1;
	else
	return 0;
}
int isEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}

void main()
{
	int choice;
	while(1)
	{
		printf("stack operations are:\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.traverse\n");
		printf("5.exit\n");
		printf("enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:peek();
			break;
			case 4:traverse();
			break;
			case 5:exit(0);
			break;
			default:printf("invalid operations\n");
		}	
	}
}	

void push(void)
{
    int ele;
	if(isFull())
	printf("stack is OVERFLOW \n");
	else
	{
		printf("enter the element:");
		scanf("%d",&ele);
		top++;
		stack[top]=ele;
		printf("element %d is pushed into the stack\n",ele);
	}
}
void pop(void)
{
	if(isEmpty())
	printf("stack is empty can not perform the operation\n");
	else
	{
		printf("element %d is popped from the stack\n",stack[top--]);
	}
}
void peek(void)
{
	if(isEmpty())
	printf("stack is empty can not perform the operation\n");
	else
	{
		printf("element %d is the topmost element of the stack\n",stack[top]);
	}
}
void traverse()
{
	if(isEmpty())
	{
	printf("stack is empty can not perform the operation\n");
	}
	else
	{
		int i;
		printf("stack elements are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}



