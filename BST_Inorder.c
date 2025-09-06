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
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
int main()
{
	int i,n,value;
	struct node *root=NULL;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	printf("Enter data");
	for(i=0;i<n;i++)
	{
		scanf("%d",&value);
		root=insert(root,value);
	}
	printf("Inorder Traversal is:");
	inorder(root);
	return 0;
}
