// Inserting data at the beginning of the LinkedList

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node {
	int value;
	struct node* next;    // Declaring Linkedlist
};

struct node* head=NULL; // Head Node of the Linked List


// Insert a value to the LINKEDLIST 

	insert(int x){
		struct node* temp;
		temp= (struct node* )malloc(sizeof(struct node));
		
		if(head!=NULL){
			(*temp).next=head;
			(*temp).value=x;
			head=temp;
		}else{
			(*temp).next=NULL;
			(*temp).value=x;
			head=temp;
		}
	}
	
	
	
	// Traverse the LINKEDLIST and Print the value store in the LINKEDLIST
	
	printElement(){
		struct node* prtemp=head;
		int count=0;
		while(prtemp!=NULL){
			printf("%dth element of the LINKEDLIST: %d\n",count,(*prtemp).value);
			prtemp=(*prtemp).next;
			count++;
		}
		
	}

// Main Routine....

main(){
	
	int n,i,counter;
	printf("Enter the number of element want to Insert: ");
	scanf("%d",&counter);

	for(i=0;i<counter;i++){
		printf("\nEnter the number insert into LINKEDLIST: ");
		scanf("%d",&n);
		insert(n);
		printElement();
		}
	}
	

