#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};
struct node *front = NULL, *rear = NULL;
void enqueue();
void dequeue();
void display();
void main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            default:printf("invalid operation \n");
        } /* End of switch */
    } /* End of while */
} /* End of main() */

void enqueue(int ele)
{
    struct node *temp = malloc(sizeof(struct node));
	printf("enter the node data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
    if(front == NULL && rear == NULL)
        front = rear = temp;
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct node *temp;
    if(front == NULL)
         printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        temp = front;
        printf("element %d is deleted\n",front->data);
        front = front->link;
        temp->link = NULL;
        free(temp);
    }
}

void display()
{
    struct node *temp = front;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
