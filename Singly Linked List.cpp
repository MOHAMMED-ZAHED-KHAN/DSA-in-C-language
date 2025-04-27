#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};                  
struct node* root=NULL;
int len;
void addnode_last(void);
void addnode_begin(void);
void addnode_middle(void);
void display(void);
void delete(void);
int length();
void main()
{
	int choice;
	while(1)
	{
		printf("enter SLL operations\n");
		printf("1. add node at last\n");
		printf("2. add node at begin\n");
		printf("3. add node at middle\n");
		printf("4. display\n");
		printf("5. delete\n");
		printf("6. length\n");
		printf("7. quit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:addnode_last();
				break;
			case 2:addnode_begin();
				break;
			case 3:addnode_middle();
				break;			
		 	case 4:display();
				break;	
			case 5:delete();
				break;	
			case 6:len=length();
				printf("length of the node is %d\n",len);
				break;	
			case 7:exit(1);
				break;
			default:printf("invalid operation\n");			
		}
	}
}
void addnode_last(void)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
void addnode_begin(void)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}
void addnode_middle(void)
{
	struct node* temp,*p;
	int loc,i=1;
	printf("enter the location:");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location\n");
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter node data:");
		scanf("%d",&temp->data);
		temp->link=NULL;
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp->link=p->link;
		p->link=temp;
	}
}
int length()
{
	int count=0;
	struct node* p;
	p=root;
	while(p!=NULL)
	{
		count++;
		p=p->link;
	}
	return count;
}
void delete(void)
{
	struct node* temp;
	int loc,i=1;
	printf("enter the location:");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location\n");
	}	
	else
	{
		struct node* p=root,*q;
		int i=1;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
void display(void)
{
	struct node* p;
	p=root;
	if(p==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d",p->data);
			p=p->link;
		}
		printf("\n\n");
	}
}
