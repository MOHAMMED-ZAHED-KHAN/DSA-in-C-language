#include <stdio.h>
#define CAPACITY 5
void insert();
void delete();
void display();
int queue[CAPACITY];
int rear = - 1;
int front = - 1;
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
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            default:
            printf("Wrong choice \n");
        } /* End of switch */
    } /* End of while */
} /* End of main() */
 
void insert()
{
    if(CAPACITY==rear)
	printf("full\n");
	else
	{
	    int ele;
	    printf("enter ele\n");
	    scanf("%d",&ele);
		queue[rear]=ele;
		printf("element %d is added\n",ele);
		rear++;
    }
} /* End of insert() */
 
void delete()
{
	if(front==rear)
	printf("empty\n");
	else
	{
        printf("Element deleted from the Queue: %d\n", queue[front]);
		front++;
	}
} /* End of delete() */
 
void display()
{
    int i;
    if (front == rear)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i < rear; i++)
            printf("%d\n", queue[i]);
    }
}
