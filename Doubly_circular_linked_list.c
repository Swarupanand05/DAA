#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head;
void create()
{
	struct node *newnode,*tmp;
	int choice=1;
	head=NULL;
	tmp=NULL;
	while(choice)
	{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&newnode->data);
	
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=tmp=newnode;
	}
	else
	{
		tmp->next=newnode;
		newnode->prev=tmp;
		tmp=newnode;
	}
	printf("\nYou want to add an element?(0/1)");
	scanf("%d",&choice);
}
}
void insert_beg()//doubly circular linked list
{
	struct node *tail;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data to insert at begin");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		
	}
	else
	{
		newnode->next=head;
		head=newnode;
		newnode->prev=head;
		tail->next=head;		
	}
}
void display()
{
	struct node *tmp;
	tmp=head;
	while(tmp->next!=tail)
	{
		printf("%d\n",tmp->data);
		
		tmp=tmp->next;
	}
	printf("\n");
}
int main()
{
	create();
	display();
	return 0;
}
