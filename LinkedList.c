#include <stdio.h>
#include <stdlib.h>
/*
CREATED BY ENRIQUE RODRIGUEZ

int a = 5;

a 0x123
+-----+
|  5  | <--- 4 bytes
+-----+

int *b = &a;

b   0x176
+-------+
| 0x123 |
+-------+


a[0]  0x122 a[1] 0x126 a[2] 0x130 a[3] 0x134  a[4] 0x138
+---------+----------+----------+----------+----------+
|    1    |    2     |    3     |    4     |    5     |
+---------+----------+----------+----------+----------+

TAIL  0x122       0x245        0x763        0x12 HEAD  0x987
+---------+ +---------+ +----------+ +---------+ +---------+
|    1    | |    2    | |    3     | |   4     | |   5     |
|  0x245  | |  0x763  | |   0x12   | | 0x987   | |  NULL   |
+---------+ +---------+ +----------+ +---------+ +---------+
^														^
|														|
TAIL												   HEAD
*/

typedef struct node
{
	int data;
	struct node *next;
} node;

node *createNode(int inputData)
{
	node *ptr = malloc(sizeof(node)); // Memory Allocation
	ptr->data = inputData;// -> for dynamic variables, . for static variables
	ptr->next = NULL;
	return ptr;
}


node *insertion(node *tail, int data)
{
	node *temp;
	if(tail == NULL)
		return createNode(data);

	temp = tail;
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = createNode(data);
	return tail;
}

void printList(node *tail)
{
	node *temp;
	if(tail == NULL)
	{
		printf("User failed to give a proper LinkedList\n");
		return;
	}
	for(temp = tail; temp != NULL; temp = temp->next)
		printf("%d%c", temp->data, (temp->next == NULL) ? '\n' : ' ');
}

node *destroyedList(node *tail)
{
	node *temp = tail, *destroy;
	
	// temp = arr[0], temp = arr[1], temp = arr[2]
	while(temp != NULL)
	{
		destroy = temp->next; // arr[1], arr[2]
		free(temp);			  // DESTROYED arr[0], DESTROYED arr[1]
		temp = destroy;		  // temp = arr[1], temp = arr[2]
	}
}

int main(void)
{
	int i, length = 5;
	node* tail = NULL;
	
	for(i = 1; i <= length; i++)
	{
		printf("We inserted %d into our LinkedList\n", i);
		tail = insertion(tail, i);
		printList(tail);
	}
	
	printList(tail);
	
	tail = destroyedList(tail);
	return 0;
}
