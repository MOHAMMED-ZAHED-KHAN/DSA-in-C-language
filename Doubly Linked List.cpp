#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;
int len;
void last(void);
void begin(void);
void middle(void);
void display(void);
void delete(void);
int length();
void main()
{
	int choice;
	while(1)
	{
	    printf("operations are:\n");
	    printf("1.last\n");
	    printf("2.begin\n");
	    printf("3.middle\n");
	    printf("4.display\n");
	    printf("5.delete\n");
	    printf("6.length\n");
	    printf("7.quit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:last();
				break;
			case 2:begin();
				break;
			case 3:middle();
				break;
			case 4:display();
				break;
			case 5:delete();
				break;
			case 6:len=length();
				printf("length is %d\n",len);
				break;
			case 7:exit(1);
				break;
			default:printf("invalid operation\n");
		}
	}
}
void last(void)
{
	struct node* temp=malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else                                // in SLL
	{
		struct node* p=root;			//	struct node* p=root;
		while(p->right!=NULL)			//	while(p->right!=NULL)
		{								//	{
			p=p->right;					//		p=p->link;
		}								//	}
		p->right=temp;					//	p->link=temp;
		temp->left=p;					//	
	}
}
void middle(void)
{
	struct node* temp,*p=root;
	int loc,i=1;
	printf("enter the location:");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location\n");
	}
	else
	{
		temp=malloc(sizeof(struct node));
		printf("enter node data:");
		scanf("%d",&temp->data);
		temp->left=NULL;
		temp->right=NULL;		
		p=root;
		while(i<loc)							// in SLL
		{
			p=p->right;							//	p-p>link
			i++;
		}
		temp->right=p->right;					//	temp->link=p->link
		p->right->left=temp;					//	p->link=temp
		temp->left=p;
		p->right=temp;
	}
}

void begin(void)
{
	struct node* temp=malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}										//	in SLL
	else									
	{										
		temp->right=root;					//	temp->link=root;
		root->left=temp;					//	root=temp;
		root=temp;							
	}										
}											



void display(void)
{
	struct node*p=root;
	if(p==NULL)
	{
		printf("no list\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d\n",p->data);			//	in SLL
			p=p->right;        				//	 p=p->link
		}
		printf("\n\n");
	}
}

int length()
{
	int count=0;
	struct node*p=root;
	while(p!=NULL)
	{
		count++;						//	in SLL
		p=p->right;						//	p=p->link
	}
	return count;
}


void delete(void)
{
	struct node* temp,*p,*q;
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
		{											//	in SLL
			p=p->right;								//	p=p->link
			i++;
		}
		q=p->right;									//	q=p->link
		p->right=q->right							//	p->link=q->link
		q->right->left=p;							//	q->link=NULL
		q->right=NULL;								//	free(q)
		free(q);
	}
}
