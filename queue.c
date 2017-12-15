// Queues Datastructure
// Author: Siddhartha Sadhukhan

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node
{
	int data;
	struct node* next;
};
struct node* top=NULL;

// Enqueue: Inserting data at the end of the linkedlist
enqueue(int x)
{
	struct node* count;
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	(*temp).next=NULL;
	(*temp).data=x;
	count=top;
	if(count==NULL)
	{	
		top=temp;
		return;
	}
	else
	{	
		while((*count).next!=NULL)
		{
			count=(*count).next;
		}
		(*count).next=temp;
		return;
	}	
}

// Dequeue= Deleting or dequeuing data at the front of the linkedlist
dequeue()
{
	struct node* temp;
	temp=top;
	if(temp!=NULL)
	{
		top=(*temp).next;
		free(temp);
	}
	else
	{
		printf("\nNothing to Dequeue");
	}
	
}

// Print all the element in the queue
printElement()
{
	struct node* temp;
	temp=top;
	while(temp!=NULL){
		printf("%3d  ",(*temp).data);
		temp=(*temp).next;
	}
}

// Main function
main()
{
	int n,nq,dq,i,j;
	
	printf("Enter the number of Element to enqueue: ");
	scanf("%d",&n);
	
		for(i=0;i<n;i++)
		{
			printf("Enter the number of element for queue: ");
			scanf("%d",&nq);
			enqueue(nq);
		}
	printElement();
	printf("\nEnter the number of element for dequeue: ");
	scanf("%d",&dq);		
			for(j=0;j<dq;j++){
				dequeue();
			}
	printElement();		
		
	getch();
}
