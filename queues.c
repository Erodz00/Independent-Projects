/* 
Queues are an implementation of a Linked List that follow
the principle of first in, first out

enqueue() - Add element to Queue
dequeue() - Removes and returns element from Queue
front() - Returns the element value at the front of the Queue without removing it
isEmpty() - Returns true if Queue size is 0
isFull() - Returns true if the Queue size equals the capacity

Initial empty queue
+------------------+

+------------------+
front			 end
------------------------------------------------
enqueue(1)
enqueue(3)
enqueue(5)
enqueue(7)

+------------------+
  1 -> 3 -> 5 -> 7 
+------------------+
front			 end

add 1
add 3
add 5
add 7
------------------------------------------------
front()
dequeue()
dequeue()
front()
enqueue(9)

+------------------+
  5  ->   7  ->  9
+------------------+
front			 end

print 1
remove 1
remove 3
print 5
add 9
------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ 
	// Individual spaces in our queue
	int data;
	struct node *next;
} node;

typedef struct Queue
{ 
	// Holds the front and end of our queue
	// Holds the space and space remaining in queue
	node *front;
	node *end;
	int size;
	int capacity;
} Queue;

int isEmpty(Queue *q)
{
	// Check if queue exists or is empty
	return q == NULL || q->size == 0;
}

int isFull(Queue *q)
{
	// if size == capacity, there is no more room in queue
	return q->size == q->capacity;
}

Queue *createQueue(void)
{
	// Create space for queue, set default values
	Queue *q = malloc(sizeof(Queue));
	q->front = NULL;
	q->end = NULL;
	q->size = 0;
	q->capacity = 10;
	
	return q;
}

// Helper Function, creates node
node *createNode(int data)
{
	node *new_node = malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void enqueue(Queue *q, int data)
{
	// Cannot add to full queue
	if(isFull(q))
	{
		printf("Queue is full, no space left to add\n");
		return;
	}
	
	// Check if q doesn't exists, if it does...
	// Check if first node doesnt exist to create our queue
	// Else, add nodes to end of queue (infers queue is made already)
	if (q == NULL)
		return;
	else if (q->front == NULL)
		q->front = q->end = createNode(data);
	else
	{
		q->end->next = createNode(data);
		q->end = q->end->next;	
	}
	q->size++;
}

void dequeue(Queue *q)
{
	// Cannot dequeue an empty queue
	if (isEmpty(q))
	{
		printf("Cannot dequeue an empty queue\n");
		return;
	}
	
	// Print value being removed as well as freeing its spot
	printf("We are removing %d from the queue\n", q->front->data);
	node *temp = q->front->next;
	free(q->front);
	q->front = temp;
	
	// Check if queue contained 1 node
	if(q->front == NULL)
		q->end == NULL;
	q->size--;
}

int front(Queue *q)
{
	// Print value of node at the front of the queue
	if (isEmpty(q))
	{
		printf("There is nothing in the queue\n");
		return -1;
	}

	return q->front->data;
}

void printQueueHelper(node *head)
{
	if (head == NULL)
		return;

	printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
	printQueueHelper(head->next);
}

void printQueue(Queue *q)
{
	// Same print function as in LinkedListAdvanced.c
	if (q == NULL || q->front == NULL)
	{
		printf("Queue is empty, cannot print\n");
		return;
	}

	printQueueHelper(q->front);
}

int main(void)
{
	Queue *q = createQueue();
	
	int menuSelection;
	while(1)
	{
		printf("\n\n(1) Enqueue\n");
		printf("(2) Dequeue\n");
		printf("(3) front\n");
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
				printf("What number do you want to enqueue? ");
				int n;
				scanf("%d", &n);
				enqueue(q, n);
				continue;
			case 2:
				printf("Dequeueing from the queue...\n");
				dequeue(q);
				continue;
			case 3:
				printf("The value in front of the queue is %d\n", front(q));
				continue;
			case 4:
				if(isEmpty(q))
					printf("The queue is empty\n");
				else
					printf("The queue is not empty\n");
				continue;
			case 5:
				if(isFull(q))
					printf("The queue is full\n");
				else
					printf("The queue is not full\n");
				continue;
			case 6:
				printQueue(q);
				continue;
			case 7:
				return 0;
			default:
				return 0;
		}
	}
	return 0;
}
