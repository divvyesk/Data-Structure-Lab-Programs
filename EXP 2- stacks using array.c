//Q: implementation of stack using an array. Create a menu driven program

#include<stdio.h>
#define max 10
int stack [max];
int top = -1;


int isFull()
{
	if(top == max-1)
	return 1;
	
	else
	return 0;
}

int isEmpty()
{
	if(top == -1)
	return 1;
	
	else 
	return 0;
}

void push(int element)
{
	if(isFull())
	{
		printf("OVERFLOW!");
	}
	top++;
	stack[top] = element;
}

int pop()
{
		if(isEmpty())
		{
			return -1;
		}
		else
		{
			int val = stack[top];
			top=top-1;
			return val;
		}
		
}

int peek()
{
	if(isEmpty())
	{
		printf("UNDERFLOW!");
	}
	
	
	return stack[top];
}

int size()
{
	if(isEmpty()) return 0;
	
	return top+1;
}

void Display()
{
	for(int i=0; i< top+1; i++)
	{
		printf("%d  ", stack[i]);
	}
}

int main()
{
		int choice;
		
		int element;
		
		printf("THIS IS A MENU DRIVEN PROGRAM!\n");
		
		while(1)
		{
				printf("Enter choice:\n(1) for pushing\n(2) for popping\n(3) for peeking\n(4) for length\n(5) for displaying elements\n(6) for exiting:\n");
				scanf("%d", &choice);
				
				switch(choice)
				{
					case 1: 
					{
						printf("Enter element to be pushed: ");
						scanf("%d", &element);
						push(element);
						printf("\n\n");
						break;
					}
					
					
					case 2:
					{
						int val = pop();
						
						if(val == -1)
						{
							printf("The given stack is empty!\n\n");
						}
						
						else
							printf("Element popped from the stack is %d\n\n", element);
						
						break;
					}
					
					case 3: //peeking
					{
						printf("Element at the top of the stack is : %d\n\n" ,peek());
						break;
					}
					
					case 4: //size
					{
						printf("The size of the stack is %d:\n\n", size());
						break;
					}
					
					case 5: //display
					{
						Display();
						printf("\n");
						break;
					}
					
					case 6:
					{
						exit(0);
					}
					
					default: 
					printf("Invalid input, try again!\n\n");
				}
		}
		
		return 0;
			
		
		
}
