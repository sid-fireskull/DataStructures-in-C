// Insert a node to the end of the LinkedList
// Author: Sid

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node {
	int data;
	struct node* next;
};

struct node* head=NULL;


// Insert a node at the end of the LinkedList

insert(int x){
	struct node* bucket;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	bucket=head;
	if(head==NULL){
		(*temp).data=x;
		(*temp).next=NULL;
		head=temp;
		return;
	}
	while((*bucket).next!=NULL){
		bucket=(*bucket).next;
	}
	(*temp).data=x;
	(*temp).next=NULL;
	(*bucket).next=temp;
	
}

// Print Element of the LinkedList

printElement(){					
	struct node* temp;
	temp=head;
	while(temp!=NULL){
		printf("%3d  ", (*temp).data );
		temp=(*temp).next;
		
	}
	printf("\n");
}

// Main Routine

main(){
	int n,input,i;
	printf("Enter the number of element want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter the Number want to Insert: ");
		scanf("%d",&input);
		insert(input);
		printElement();
	}
	getch();
}
