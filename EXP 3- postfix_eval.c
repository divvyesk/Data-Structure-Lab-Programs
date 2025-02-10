//Q: Write a program to evaluate postfix expression using stack ADT

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char s[100];
char arr[100];
int top = -1;
int op1= 0;
int op2 =0;

bool isEmpty()
{
	if(top == -1)
	return true;
	
	else
	return false;
}

bool isFull()
{
		if(top == strlen(arr)-1)
		return true;
		
		else
		return false;
}

int pop()
{
		if(isEmpty())
		{
			printf("UNDERFLOW!");
			return 0;
		}
		
		else
		{
		int val= s[top];
		top--;
		return val;
		}
}

void push(int element)
{
		if(isFull())
		printf("OVERFLOW!");
		
		else
		{
			top++;
			s[top]= element;
		}
}

int perform(char op1, char op2, char op)
{
	switch(op)
	{
		case '+': 
		{
			return op1+ op2;
			break;
		}
		
		case '-':
		{
			return op1- op2;
			break;
		}
		
		case '*':
		{
			return op1* op2;
			break;
		}
		
		case '/':
		{
			return op1/op2;
			break;
		}
		
		case '%':
		{
			return op1% op2;
			break;
		}
		
		case '^':
		{
			return op1^ op2;
			break;
		}
		
		default:
		printf("Enter a valid operator! ");
		return 0;
	}
}


int main()
{
	printf("Enter an expression: ");
	gets(arr);
	
	for(int i=0; i<strlen(arr); i++)
	{
		if(isalnum(arr[i]))
		{
			push(arr[i]-'0');
		}
		
		
		if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%' ||arr[i] == '^')
		{
			op2= pop();
			op1= pop();
			
			int res= perform(op1, op2, arr[i]);
			
			push(res);
		}
	}
	
	int result = (int) s[top];
	printf("%d", result);
	
	return 0;
}
