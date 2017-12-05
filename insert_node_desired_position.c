// Inserting data in the linkedlist in the desired position
// Author: Siddhartha Sadhukhan

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node {
	int data;
	struct node* next;
};
struct node* head=NULL;

// Inserting node at the beginning of the LinkedList

insert(int x){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(head!=NULL){
		(*temp).data=x;
		(*temp).next=head;
		head=temp;
	}else{
		(*temp).data=x;
		(*temp).next=NULL;
		head=temp;
	}
}


// Print all the element of the LinkedList

printElement()    
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%3d  ",(*temp).data);
		temp=(*temp).next;
	}
}


// Insert a node in Desired position and assigning a Value

modNode(int pos, int value){
	int counter=1;
	struct node* temp;
	struct node* temp1;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp=head;
	while(temp!=NULL){
		if(counter==(pos-1)){
			(*temp1).data=value;
			(*temp1).next=(*temp).next;
			(*temp).next=temp1;
			break;
		}
		counter++;
		temp=(*temp).next;
	}
}


// Main Routine

main(){
	int n,i,x,y,val;
	printf("Enter the element you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter the Element: ");
		scanf("%d",&x);
		insert(x);
		printElement();
	}
	printf("\nElement Inserted Successfully");
	printf("\nEnter the Position you want to insert a New node: ");
	scanf("%d",&y);
	printf("\n Enter the value of new NODE: ");
	scanf("%d",&val);
	modNode(y,val);
	printElement();
	getch();
}
