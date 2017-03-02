// Reverse the items in the Linked List
// Author: Sid

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node {
	int value;
	struct node* next;
};
struct node* head=NULL;


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
	
	
	
	// Traverse the LINKEDLIST and Print the value portion of the LINKEDLIST
	
	printElement(){
		struct node* prtemp=head;
		int count=0;
		while(prtemp!=NULL){
			printf("%dth element of the LINKEDLIST: %d\n",count,(*prtemp).value);
			prtemp=(*prtemp).next;
			count++;
		}
		
	}
	
	// Reverse a Linked List
	
	reverse(){
		struct node *current, *next, *prev;
		prev=NULL;
		current=head;
		while(current!=NULL){
			next=(*current).next;
			(*current).next=prev;
			prev=current;
			current=next;
		}
		head=prev;
	}
	
	
	
// Print Element in the LinkedList using Recursion

printrecur(struct node* rec){
	if(rec==NULL)
	{
		return;
	}
	printf("%3d  ",(*rec).value);
	rec=(*rec).next;
	printrecur(rec);
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
		
		printf("\n Reversing the LinkedLIst: \n");
		getch();
		reverse();
		printElement();
		getch();
		
		printf("\n Print Elements of the LinkedList using Recursion: ");
		printrecur(head);
	}
	
