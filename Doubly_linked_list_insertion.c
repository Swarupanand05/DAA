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
void insert_beg()
{
	struct node *prev,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
	//newnode->prev=head;
	//newnode->next=head->next;
	//head=newnode;
}
void insert_end()
{
	struct node *prev,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
}
void insert_pos()
{
	struct node *tmp,*prev,*newnode;
	int pos,i=1;
	printf("enter position");
	scanf("%d",&pos);
	if(pos<1)
	{
		printf("invalid position");
	}
	else if(pos==1)
	{
		insert_beg();
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		tmp=head;
		while(i<pos)
		{
			tmp=tmp->next;
			i++;
		}
		newnode->prev=tmp;
		newnode->next=tmp->next;
		tmp->next=newnode;
		         
			tmp->next->prev = newnode;
		
		
	}
}
void insert_after_pos()
{
	struct node *tmp, *newnode;
	int pos, i = 1;
	printf("enter position");
	scanf("%d", &pos);

	if (pos < 1)
	{
		printf("invalid position");
	}
	else
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		newnode->prev = NULL;

		tmp = head; 
		while (i < pos)
		{
			tmp = tmp->next;
			i++;
		}

		newnode->next = tmp->next;
		newnode->prev = tmp;

		if (tmp->next != NULL) 
			tmp->next->prev = newnode;

		tmp->next = newnode;
	}
}

void display()
{
	struct node *tmp;
	tmp=head;
	while(tmp!=NULL)
	{
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.create node\n");
		printf("2.insert at begin\n");
		printf("3.insert at end\n");
		printf("4.insert at position\n");
		printf("5.insert after position\n");
		printf("6.display\n");
		printf("enter choice");
		scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:create();
		break;
		case 2:
		insert_beg();
		break;
		case 3:
			insert_end();
			break;
		case 4:
			insert_pos();
			break;
		case 5:
			insert_after_pos();
			break;
		case 6:display();
		break;
		case 7:
			exit(0);
		default:
			printf("invalid choice");
	}
}
return 0;
}
