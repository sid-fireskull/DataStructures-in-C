// Balancing parentheses using stack datastructure
// Author: Siddhartha Sadhukhan

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


struct node{
	char data[1];
	struct node* next;
};

struct node* top=NULL;


// Push data into the stack
push(char x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(top==NULL)
	{
		(*temp).data[0]= x;
		(*temp).next=NULL;
		top=temp;
	}
	else
	{
		(*temp).data[0]=x;
		(*temp).next=top;
		top=temp;
	}
}


// Pop operation
pop(void)
{
	struct node* temp;
	temp=top;
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		top=(*temp).next;
		free(temp);
		return 1;
	}
	
}

// Checking for pair parentheses
int parenthesesPairCheck(char opening, char closing)
{
	if(opening=='(' && closing==')')
	{
		return 1;
	}
	else if(opening =='{' && closing =='}')
	{
		return 1;
	}
	else if(opening=='[' && closing==']')
	{
		return 1;
	}
	return 0;
}

// Current status of the stack
stackstatus(void){
	struct node* temp;
	temp=top;
	while(temp!=NULL){
		printf("%c  ",(*temp).data[0]);
		temp=(*temp).next;
	}
}


// Checking Parentheses function
int checkingExpression(char *exprssn)
{
	int i=0;
	while(*(exprssn+i) != '\0')
	{
		// stackstatus();
		if(*(exprssn+i) == '(' || *(exprssn+i) == '{' || *(exprssn+i) == '[')
		{
			push(*(exprssn+i));
		}
		else if(*(exprssn+i) == ')' || *(exprssn+i) == '}' || *(exprssn+i)==']')
		{
			if(top == NULL || parenthesesPairCheck((*top).data[0], *(exprssn+i)) != 1)
			{
				return 0;
			}
			else
			{
				pop();
			}
		}
		i=i+1;
	}
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// Main function
int main()
{
	int result;
	char bucket[100];
	printf("Enter the Expression: ");
	scanf("%s", &bucket);
	result = checkingExpression(bucket);
	if(result == 1)
	{
		printf("\n\nExpression is balanced");
	}
	else
	{
		printf("\n\nExpression is not balanced");
	}
}
