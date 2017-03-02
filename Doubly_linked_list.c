
// Doubly Linked List

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Defining node for doubly linked list
struct node {
	int data;
	struct node* prev;
	struct node* next;
};
struct node* head=NULL;

insert(int value){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(head==NULL){
		(*temp).data=value;
		(*temp).prev=NULL;
		(*temp).next=NULL;
		head=temp;
	}else{
		(*head).prev=temp;
		(*temp).data=value;
		(*temp).prev=NULL;
		(*temp).next=head;
		head=temp;
	}
}


//Reverse the doubly Linked List

reverse(){
	struct node *temp,*bucket;
	temp=head;
	while(temp!=NULL){
		{
			bucket=(*temp).prev;
			(*temp).prev=(*temp).next;
			(*temp).next=bucket;
			temp=(*temp).prev;
		}
		printf("%d",temp);
		head=temp;
	}
}

// Print Element of the Node

printElement(){
	struct node* temp;
	temp=head;
	while(temp!=NULL){
		printf("%3d  ",(*temp).data);
		temp=(*temp).next;
	}
}

// Main Routine

main(){
	int i,n,x;
	printf("Enter the number of element want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter the element: ");
		scanf("%d",&x);
		insert(x);
		printElement();
	}
	getch();
	printf("\nReverse Doubly Linked List");
	reverse();
	printElement();
}
