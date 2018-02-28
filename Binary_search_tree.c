// Program to create a binary search tree and search item within the binary search tree
// Author: Siddhartha Sadhukhan
#include<stdio.h>
#include<stdlib.h>

// Defining the node
struct node {
	struct node* left;
	int data;
	struct node* right; 
};

struct node* root= NULL;

// Function Creating a new node
struct node* newnode(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	(*temp).data = x;
	(*temp).left = NULL;
	(*temp).right = NULL;
	return temp;
}


// Function to Insert item to Binary Search Tree
struct node* insert(struct node* rootptr, int input)
{
	if(rootptr == NULL)
	{
		rootptr=newnode(input);
	}
	else if(input <= (*rootptr).data)
	{
		(*rootptr).left = insert((*rootptr).left, input);
	}
	else if(input > (*rootptr).data)
	{
		(*rootptr).right = insert((*rootptr).right, input);
	}
	return rootptr;
}


// Function to Search for item in Binary Search Tree
int search(int x,struct node* rootptr)
{
	if(rootptr==NULL)
	{
		return 0;
	}
	else if((*rootptr).data==x)
	{
		return 1;
	}
	else if(x<=(*rootptr).data)
	{
		return search(x,(*rootptr).left);
	}
	else
	{
		return search(x,(*rootptr).right);
	}
	return 0;
}


// Main Function
int main()
{
	
	int n,i, data, itemtosearch, flag;
	printf("Number of Element you want to insert: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter the number: ");
		scanf("%d", &data);
		root = insert(root, data);
	}
	printf("\n\nEnter the number to search: ");
	scanf("%d", &itemtosearch);
	flag = search(itemtosearch, root);
	if(flag==1)
	{
		printf("\nSearched element FOUND!!");
	}
	else
	{
		printf("\nSearched element NOT FOUND!!");
	}
	getch();
}
