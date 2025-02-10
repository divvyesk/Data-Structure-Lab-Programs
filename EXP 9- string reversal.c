//Q: Write a program to reverse a string using Stack

#include<stdio.h>
#define SIZE 5
#include<stdbool.h>

int s[SIZE]= {};
int arr[SIZE]= {};
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
		if(top == SIZE-1)
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


int main()
{
	
	
	
	printf("Enter a string of integers: ");
	for(int i=0; i<SIZE; i++)
	{
		scanf("%d", &arr[i]);
		push(arr[i]);
	}
	
	for(int i=0; i<SIZE; i++)
	{
		arr[i]= pop();
		printf("%d ", arr[i]);
	}
	
	
	
	return 0;
	
}
