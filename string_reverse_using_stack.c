// Reverse a string using stack datastructure
// Author: Siddhartha Sadhukhan

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node
{
	char data[1];
	struct node* next;
};

struct node* top=NULL;  // top always point at the top of the stack


// push function

push(char x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		(*temp).data[0] = x;
		(*temp).next = NULL;
		top=temp;	
	}
	else
	{

		(*temp).data[0] = x;
		(*temp).next = top;
		top=temp;
	}
}

// pop function

char* pop(void)
{
	struct node* temp;
	temp=top;
	if(temp==NULL)
	{
		exit;
		
	}
	else
	{
		top=(*temp).next;
		return (*temp).data;
	}	
}

// Main function

int main()
{
	char bucket[50];
	int length,n;
	printf("Enter a string to reverse: ");
	scanf("%s",bucket);
	length=strlen(bucket);
	for(n=0;n<length;n++)
	{
		
		push(bucket[n]);
		
	}
	printf("\n\n Reverse String: ");
	for(n=0;n<length;n++)
	{
		
		bucket[n] = *pop();
		printf("%c", bucket[n]);
	}

}
