/* 
Stacks are an implementation of a Linked List that follow
the principle of first in, last out

push() - Add element to Stack
pop() - Removes and returns element from Stack
peek() - Returns the element value at the top of the stack without removing it
isEmpty() - Returns true if stack size is 0
isFull() - Returns true if the stack size equals the capacity


|   | <-- Initial empty Stack
|   |
|   |
|   |
|   |
+---+
------------------------------------------------------
push(1)
push(3)
push(5)
push(7)

|   | 
| 7 | <-- Top of stack, only readily accessible value
| 5 |
| 3 |
| 1 |
+---+

add 1
add 3
add 5
add 7
------------------------------------------------------
peek();
pop();
pop();
peek();
push(9);

|   | 
|   | 
| 9 |
| 3 | <-- Top of stack
| 1 |
+---+

print 7
remove 7
remove 5
print 3
add 9
------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define FULLSTACK 10 

typedef struct node
{ // Fields/Members
	int data;
	struct node *next;
} node;

int isEmpty(node *stack)
{
	return stack == NULL; // Stack is empty when stack doesn't exist
}

int isFull(node *stack)
{
	node *temp = stack;
	int count = 0;
	
	// FULLSTACK represents 10 in this instance
	// If we count 10 nodes, we know our stack is full
	for(int i = 0; i < FULLSTACK; i++)
	{
		if(temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		else
			break;
	}
	return (count == FULLSTACK);
}

node *push(node *stack, int data)
{
	// Cannot push onto full stack
	if(isFull(stack))
	{
		printf("Stack is full\n");
		return stack;
	}
	
	// Create node function almost identical to createNode()
	// in LinkedList.c, except our next value is set to the stack pointer
	node *createdNode = malloc(sizeof(node)); // Check for errors
	createdNode->data = data;
	createdNode->next = stack;
	stack = createdNode;
	return stack;
}

node *pop(node *stack)
{
	// Can't pop something that doesn't exist/equals NULL
	if(isEmpty(stack))
	{
		printf("Cannot pop an empty stack\n");
		return NULL;
	}
	
	// Have to maintain top of stack and next value
	node *temp = stack;
	printf("%d has been popped from the stack\n", temp->data);
	
	// Shift stack over and free its previous position (temp)
	stack = stack->next;
	temp->next = NULL;
	free(temp);
	return stack;
}

int peek(node *stack)
{
	// Similar to pop except we don't remove the value at the top of the stack
	if(isEmpty(stack))
	{
		printf("There is nothing in the stack\n");
		return -1;
	}
	return stack->data;
}

void printStack(node *stack)
{
	printf("The stack is: ");
	if(isEmpty(stack))
		printf("Stack is empty, cannot print empty stack\n");
	else
	{
		// Identical to printList in LinkedList.c
		node *temp = stack;
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(void)
{
	node *topOfStack = NULL;
	
	int menuSelection;
	while(1)
	{
		printf("\n\n(1) Push\n");
		printf("(2) Pop\n");
		printf("(3) Peek\n");
		printf("(4) isEmpty\n");
		printf("(5) isFull\n");
		printf("(6) Print\n");
		printf("(7) Exit\n");
		printf("Enter a selection :");
		scanf("%d", &menuSelection);
		printf("\n");
		switch(menuSelection)
		{
			case 1:
				printf("What number do you want to push? ");
				int n;
				scanf("%d", &n);
				topOfStack = push(topOfStack, n);
				continue;
			case 2:
				printf("Popping from the stack...\n");
				topOfStack = pop(topOfStack);
				continue;
			case 3:
				printf("The value peeked on top of the stack is %d\n", peek(topOfStack));
				continue;
			case 4:
				if(isEmpty(topOfStack))
					printf("The stack is empty\n");
				else
					printf("The stack is not empty\n");
				continue;
			case 5:
				if(isFull(topOfStack))
					printf("The stack is full\n");
				else
					printf("The stack is not full\n");
				continue;
			case 6:
				printStack(topOfStack);
				continue;
			case 7:
				return 0;
			default:
				return 0;
		}
	}
	return 0;
}
