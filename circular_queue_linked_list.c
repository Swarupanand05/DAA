#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;	
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int x)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	if(rear==NULL)
	{
		front=rear=newnode;
		rear->next=front;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=front;
	}
}
void dequeue()
{
	struct node *temp;
	temp=front;
	if(front==-1&&rear==-1)
	{
		printf("empty list");
	}
	else if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		printf("dequeued data is:%d ",front->data);
		front=front->next;
		rear->next=front;
		free(temp);	
	}
	printf("\n");		
}
void peek()
{
	if(front==-1&&rear==-1)
	{
		printf("empty list");
	}
	else
	{
		printf("peeked data:%d ",front->data);
	}
	
}
void display()
{
	struct node *temp;
	temp=front;
	if(front==-1&&rear==-1)
	{
		printf("empty list");
	}
	else
	{
		while(temp->next!=front)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d ",temp->data);
	}
}
int main()
{
	int num,value,i,choice;
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

