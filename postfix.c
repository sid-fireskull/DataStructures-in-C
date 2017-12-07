// Postfix operation using stack datastructure
// Author: Siddhartha Sadhukhan

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;

// push data to the stack
push(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		(*temp).data=x;
		(*temp).next=NULL;
		top=temp;
	}
	else
	{
		(*temp).data=x;
		(*temp).next=top;
		top=temp;
	}
}

// pop data from the stack
int pop(void)
{
	struct node* temp;
	temp=top;
	if(top==NULL)
	{
		printf("\nStack is empty");
		exit;
	}
	else
	{
		top=(*temp).next;
		return (*temp).data;
	}
}

// Check for valid operator
int isOperator(char x)
{
	if(x =='+'|| x == '-' || x == '*' || x == '/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//  current stack status
stackstatus(void)
{
	struct node* temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d  ",(*temp).data);
		temp=(*temp).next;
	}
}

//  main function
int main()
{
   char buffer[80];
   const char delimiter[2] = " ";
   char *token;
   int result, operand1, operand2, temp;
   printf("Enter the Expression (Use space as delimiter): ");
   fgets(buffer, 80, stdin);
   token = strtok(buffer, delimiter);
   
  // spliting string using defined delimiter
   while( token != NULL ) {
      if(isOperator(*token)==1)
      {
      	operand1= pop();
      	operand2= pop();
      	if(*token == '+')
	{
		result = operand2+operand1;
      	}
      	else if(*token == '-')
      	{
      		result = operand2-operand1;
      	}
      	else if(*token == '*')
      	{
      		result = operand2*operand1;
      	}
      	else if(*token == '/')
      	{
      		result = operand2/operand1;
      	}
      	push(result);
      }
	  else
	  {
	  	temp= atoi(token);
	  	push(temp);
	  }
    
      token = strtok(NULL, delimiter);
   }  
   printf("\nResult: %d",(*top).data);
   return(0);	
}
