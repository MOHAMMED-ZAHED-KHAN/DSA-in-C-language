
				//  STACK IMPLEMENTATION USING SINGLE LINKED LIST


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};
struct node* top=NULL;
void push();
void pop();
void peek();
void traverse();
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
void push()
{
	struct node* temp=malloc(sizeof(struct node));
	printf("enter the node data\n");
	scanf("%d",&temp->data);
	temp->link=top;
	top=temp;
}
void pop()
{
	if(top==NULL)
	printf("list is empty\n");
	else
	{
		struct node* temp=top;
		printf("element %d is popped from stack\n",top->data);
		top=top->link;
		temp->link=NULL;
		free(temp);
	}
}
void traverse()
{
	struct node* temp=top;
	if(top==NULL)
	printf("list is empty\n");
	else
	{
	    printf("stack elements are:\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}
void peek()
{
	struct node* temp=top;
	if(top==NULL)
	printf("list is empty\n");
	else
	printf("top element is %d\n",top->data);
}
