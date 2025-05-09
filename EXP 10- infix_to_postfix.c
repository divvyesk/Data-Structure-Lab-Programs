#include<stdio.h>
#include<ctype.h>
#define MAX 10
#include<string.h>
#include<stdbool.h>

char s[MAX]; //to store the operators 
char op[MAX]; //to store the output postfix expression
int top = -1;

bool isEmpty()
{
	if(top == -1)
	return true;
	
	else 
	return false;
}

bool isFull()
{
	if(top==MAX-1)
	return true;
	
	else
	return false;
}

void push(int x)
{
	if(isFull())
	printf("OVERFLOW!");
	
	else{
	top++;
	s[top]= x;
	}
}

void pop()
{
	if(isEmpty())
	printf("UNDERFLOW!");
	
	else
	{
		top--;
	}
}


int precedence(char ch)
{
	switch(ch)
	{
		case '+':
		
		case '-':
		
			return 1;
		
		case '*':
		
		case '/':
				
			return 2;
			
		case '^':
			
			return 3;
	}
	
	return -1;
}



int main()
{
	
	char ip[MAX];
	
	printf("Input an expression: ");
	scanf("%s", ip);

	int lenin= strlen(ip);
	
	for(int i=0; i<lenin; i++)
	{
		//case1: if it is an operand, append it to the output string
		if(isalnum(ip[i]))
		{
			int len= strlen(op);
			op[len]=ip[i];
			op[len+1]= '\0';
		}
		
		//case2: if opening parenthesis, push it into the stack
		else if(ip[i] == '(')
		{
			push(ip[i]);
		}
		
		//case3: if closing parenthesis, pop all the operators in the stack till ( is encountered
		else if(ip[i] == ')')
		{
			while((!isEmpty()) && (s[top] != '(')) //op main s[top] concat
			{
				int len= strlen(op);
				op[len]=s[top];
				op[len+1]= '\0';
				pop();
			}
			
			pop(); //to discard the leftover ( 
		}
		
		//case4: if it is an operator, it will be pushed into the stack if it has higher precedence than s[top] and 
		//if it doesn't it will be appended in the output expression till we find a (
		else
		{
			while((!isEmpty()) && (s[top] != '(') && (precedence(s[top]) >= precedence(ip[i])))
			{
				int len= strlen(op);
				op[len]=s[top];
				op[len+1]= '\0';
				pop();
			}
			
			push(ip[i]); //incase any of the while loop condition becomes false, the operator is pushed in
			//the stack (ex. precedence of ip[i] was greater than s[top])
		}
		
	}

	//incase the expression is over but there is still something left in the stack, append all of it in the output expression
	while(!isEmpty())
	{
		int len= strlen(op);
		op[len]=s[top];
		op[len+1]= '\0';
		pop();
	}
	
	//display result
	for(int i=0; i<strlen(op); i++)
	{
		printf("%c", op[i]);
	}
}
