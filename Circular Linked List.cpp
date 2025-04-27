#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};                  
struct node* tail=NULL;  	// here instead of root in SLL , we have tail 
int len;
void addnode_last(void);
void addnode_begin(void);
void addnode_middle(void);
void display(void);
void deletefirst_node(void);
void deletelast_node(void);
void deletemiddle_node(void);
int length();
void main()
{
	int choice;
	while(1)
	{
		printf("enter CLL operations\n");
		printf("1. add node at last\n");
		printf("2. add node at begin\n");
		printf("3. add node at middle\n");
		printf("4. display\n");
		printf("5. delete first node\n");
		printf("6. delete last node\n");
		printf("7. delete middle node\n");
		printf("8. length\n");
		printf("9. quit\n");
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
			case 5:deletefirst_node();
				break;	
			case 6:deletelast_node();
				break;
			case 7:deletemiddle_node();
				break;
			case 8:len=length();
				printf("length of the node is %d\n",len);
				break;	
			case 9:exit(1);
				break;
			default:printf("invalid operation\n");			
		}
	}
}


void addnode_last(void)
{
	struct node* temp=malloc(sizeof(struct node));
	printf("enter node data:\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(tail==NULL) 		 // for single node
	{
		temp->link=temp;
		tail=temp;
	}
	else  			// for multiple nodes
	{
		temp->link=tail->link;
		tail->link=temp;
		tail=temp;
	}
}


void addnode_begin(void)
{
	struct node* temp=malloc(sizeof(struct node));
	printf("enter node data:\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(tail==NULL) 		 // for single node
	{
		temp->link=temp;
		tail=temp;
	}
	else  			// for multiple nodes
	{
		temp->link=tail->link;
		tail->link=temp;
	}
}



void deletefirst_node(void)
{
	if(tail->link==tail)				// for single node
	{
		tail->link=NULL;
		free(tail);
	}
	else								// for multiple nodes
	{
		struct node* p=tail->link;
		tail->link=p->link;
		p->link=NULL;
		free(p);
	}
}





void deletelast_node(void)
{
	if(tail->link==tail)				// for single node
	{
		tail->link=NULL;
		free(tail);
	}
	else								// for multiple nodes
	{
		struct node* p=tail->link;
		while(p!=tail->link)
		{
			p=p->link;
		}
		p->link=tail->link;
		tail->link=NULL;
		free(tail);
		tail=p;
	}
}




int length()
{
	int count=0;
	struct node* p=tail->link;
	do
	{
		count++;
		p=p->link;
	}while(p!=tail->link);
	return count;
}



void deletemiddle_node(void)
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
		struct node* p=tail->link,*q;
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





void addnode_middle(void)
{
	struct node* temp,*p=tail->link;
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
		p=tail->link;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp->link=p->link;
		p->link=temp;
	}
}







void display(void)
{
	struct node* p=tail->link;
	do
	{
		printf("%d\n",p->data);
		p=p->link;
	}
	while(p!=tail->link);
}
