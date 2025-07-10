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
void insert_beg() {
    struct node *newnode, *tail;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data at beginning: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
        
    }
}
void insert_end()
{
	struct node *newnode, *tail,*tmp;
	if(head==NULL)
	{
		insert_beg();
	}
	else
	
	{
		newnode = (struct node*)malloc(sizeof(struct node));
    	printf("Enter data at end: ");
    	scanf("%d", &newnode->data);
		tail=head;
		while(tail->next!=head)
		{
			tail=tail->next;
		}
		newnode->next=head;
		tail->next=newnode;
		}
}
void insert_pos()
{
	//int l = getLength();
	struct node *tmp, *newnode;
	int pos, i = 1;

	printf("Enter position: ");
	scanf("%d", &pos);

	if (pos < 1) {
		printf("Invalid position\n");
		return;
	}

	if (pos == 1) {
		insert_beg();
	} else {
		newnode = (struct node*)malloc(sizeof(struct node)); // allocate before use
		printf("Enter data: ");
		scanf("%d", &newnode->data);

		tmp = head;
		while (i < pos - 1) {
			tmp = tmp->next;
			i++;
		}
		newnode->next = tmp->next;
		tmp->next = newnode;
	}
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
	int choice;
	while(1)
	{
		printf("1.create node\n");
		printf("2.insert at begin\n");
		printf("3.insert at end\n");
		printf("4.insert at position\n");
		printf("5.display\n");
		printf("enter choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
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
				display();
				break;
			default:
			printf("invalid choice");
		}
	}
	return 0;
	//create();
	//display();
	//insert_beg();
	//display();
	//insert_end();
	//display();
}

