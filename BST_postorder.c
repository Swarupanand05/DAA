#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node *newnode;
struct node *create(int value)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node *insert(struct node *root,int value)
{
	if(root==NULL)
	{
		return create(value);
	}
	else if(value<root->data)
	{
		root->left=insert(root->left,value);
	}
	else
	{
		root->right=insert(root->right,value);
	}
	return root;
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	struct node *root=NULL;
	int value,size,i;
	printf("enter count of the elements:");
	scanf("%d",&size);
	printf("Enter elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&value);
		root=insert(root,value);
	}
	printf("preorder is: ");
	postorder(root);
	return 0;
}
