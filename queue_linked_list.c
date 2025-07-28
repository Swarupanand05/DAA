#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node * front=NULL;
struct node * rear=NULL;
void enqueue(int x)
{
	int value;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	if(front==NULL && rear==NULL)
	{
		front = rear = newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	struct node *temp;
	temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("empty list");
	}
	else
	{
		printf("dequeued data is:%d ",front->data);
		front=front->next;
		free(temp);
		
	}
	printf("\n");
	
}
void peek()
{
	struct node *temp;
	temp=front;
	
	if(front==NULL && rear==NULL)
	{
		printf("empty list");
	}
	else
	{
		printf("peeked data:%d ",front->data);	
	}
	printf("\n");
}
void display()
{
	struct node *temp;
	temp=front;
	
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}

int main()
{
	int choice;
	
	int value,num,i;
	
		while(1)
		{
			printf("\n1.enqueue\n 2.dequeue\n 3.peek\n 4.display\n 5.exit\n");
			printf("enter choice:");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
			
			
			printf("enter no of data");
			scanf("%d",&num);
	
			for(i=0;i<=num;i++)
			{
				printf("enter value that you want to insert in queue");
				scanf("%d",&value);
				enqueue(value);
				
			}
			break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			default:
				printf("invalid choice");
}
}
}
