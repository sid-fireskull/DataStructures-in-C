// Linkedlist using charecter
// Author: Siddhartha Sadhukhan


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Defining node

struct node {
	char data[1];
	struct node* next;
};


struct node* top=NULL;

push(char x){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top!=NULL){
		(*temp).data[0]=x;
		(*temp).next=top;
		top=temp;
	}else{
		(*temp).data[0]=x;
		(*temp).next=NULL;
		top=temp;	
	}
	stackstatus();
}

// Print the inserted element in the Linked List

stackstatus(){
	struct node* temp;
	temp=top;
	while(temp!=NULL){
		printf("%3c  ",(*temp).data[0]);
		temp=(*temp).next;
	}
}

main(){
	char expression[50];
	int i;
	printf("Enter any Expression: ");
	scanf("%s",&expression);
	for(i=0;i<strlen(expression);i++){
		push(expression[i]);
	}
	getch();
}

