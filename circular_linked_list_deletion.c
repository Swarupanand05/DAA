#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;	
};
struct node *head;
void create()
{
	struct node *tmp,*newnode;
	head=NULL;
	int choice=1;
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=tmp=newnode;
		}
		else
		{
			tmp->next=newnode;
			tmp=newnode;
		}
		tmp->next=head;
		printf("want to store a data(0/1)");
		scanf("%d",&choice);
	}
}
void delete_beg()
{
	struct node*tail=head;
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		head=head->next;
		while(tail->next!=head)
		{
			tail=tail->next;
		}
		struct node *tmp=head;
		head = head->next;
    	tail->next = head;
		free(tmp);
	}
}
void delete_end()
{
	
}
void display()
{
	struct node *tmp;
	if(head==NULL)
	{
		printf("empty list");
	}
	else
	{
		tmp=head;
		while(tmp->next!=head)
		{
			printf("%d",tmp->data);
			tmp=tmp->next;
		}
		printf("%d\n",tmp->data);
	}	
}
int main()
{
	create();
	delete_beg();
	display();
}
