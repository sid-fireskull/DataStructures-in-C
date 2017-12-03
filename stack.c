// Stack Datastructures
// Author: Siddhartha Sadhukhan

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;  // top always point to the top of the stack

// Push data at the top of the stack
push(int x)
{
	struct node* temp
	temp = ()struct node*)malloc(sizeof(node));
	if(top==NULL)
	{
		temp.data=x;
		temp.next= NULL;
		top=next;
	}
	else
	{
		temp.data=x;
		temp.next=top;
		top=next;	
	}
}


// Delete data at the top of the stack
int pop(void)
{
	struct node* temp;
	temp=top;
	if(temp==NULL)
	{
		printf("Stack is Empty");
	}
	else
	{
		top=(*temp).next;
		return (*temp).data;
	}
	
}


// Current status of the stack
status(void)
{
	printf("Stack Status.....");
	if(top==NULL)
	{
		printf("Stack is Empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%3d", (*temp).data);
			temp=(*temp).next;
		}
	}
	printf("\n\n");
	
}

int main()
{
	int n=5,x;
	while(n<10)
	{
		printf("\t \t MENU \t \t\n-----------------------------------------------------\n");
		printf("1. push operation\n");
		printf("2. pop operation\n");
		printf("3. Stack status\n");
		printf("4. Exit\n");
		printf("\nYour Choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\nEnter the element want to push in the stack: ");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3:
				status();
				break;
			case 4:
				exit;
		}
	}
}
