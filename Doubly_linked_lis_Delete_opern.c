#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head,*tail;
void create()
{
	struct node *tmp,*newnode;
	head=NULL;
	tail=NULL;
	int choice=1;
	while(choice)
	{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		newnode->prev=tail;
		tail->next=newnode;
		tail=newnode;
	}
	printf("Do you want to add data(0/1)");
	scanf("%d",&choice);
	}
}
void delete_beg()
{
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		struct node *tmp;
		tmp=head;
		head=head->next;
			head->prev=NULL;
		free(tmp);
	}
}
void delete_end()
{
	struct node *tmp;
	if(tail==NULL)
	{
		printf("list is empty");
	}
	else
	{
		tmp=tail;
		tail->prev->next=NULL;
		tail=tail->prev;
		free(tmp);
	}
}
void delete_pos()
{
	int pos,i=1;
	struct node *tmp;
	tmp=head;
	printf("enter position");
	scanf("%d",&pos);
	while(i<pos)
	{
		tmp=tmp->next;
		i++;
	}
	tmp->prev->next=tmp->next;
	tmp->next->prev=tmp->prev;
	free(tmp);
}
void display()
{
	struct node *tmp=head;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->data);
		tmp=tmp->next;
		
	}
	printf("\n");
}

int main()
{
	int choice;
	while(1)
	{
		printf("1.create node\n");
		printf("2.delete at begin\n");
		printf("3.delete at end\n");
		printf("4.delete at position\n");
		printf("5.display\n");
		printf("enter choice");
		scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:create();
		break;
		case 2:
			delete_beg();
		break;
		case 3:
			delete_end();
			break;
		case 4:
			delete_pos();
			break;
		
		case 5:display();
		break;
		case 6:
			exit(0);
		default:
			printf("invalid choice");
	}
}
return 0;
}
