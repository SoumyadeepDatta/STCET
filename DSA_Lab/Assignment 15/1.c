#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 40

int pop();
void push(int);

char postfix[SIZE];
int stack[SIZE], top = -1;

int main()
{
	int i, a, b, result, pEval;
	char ch;
	
	for(i=0; i<SIZE; i++)
	{
		stack[i] = -1;
	}
	printf("\nEnter a postfix expression: ");
	scanf("%s",postfix);

	for(i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(isdigit(ch))
		{
			push(ch-'0');
      /*if we just write push(ch) then we will be able to insert the 
      ASCII value of that character 'ch' but not the actual value of 
      'ch'. So to get the actual value of 'ch' we must subtract ASCII 
      value of 0 from the ASCII value of character.
      Example: we need to push 1. ASCII value of 1 is 49 and the ASCII 
      value of 0 is 48. So 49-48=1.*/
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '%': result = a%b;
					  break;	  
			}
			
			push(result);
		}
		else
		{
			printf("\nEnter valid expression");	
			exit(-1);
		}
	
	}

	pEval = pop();
	
	printf("\nThe postfix evaluation is: %d\n",pEval);
	
	return 0;
}

void push(int n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack overflow. Enter valid expression!\n");
		exit(-1);
	}
}
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Stack underflow. Enter valid expression!\n");
		exit(-1);
	}
}	
