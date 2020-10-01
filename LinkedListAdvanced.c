#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef struct LinkedList
{
	node *head;
	node *tail;
} LinkedList;

LinkedList *createList(void)
{
	LinkedList *new_list = malloc(sizeof(LinkedList));
	new_list->head = NULL;
	new_list->tail = NULL;

	return new_list;
}

node *createNode(int data)
{
	node *new_node = malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void tailInsert(LinkedList *list, int data)
{
	if (list == NULL)
		return;
	else if (list->tail == NULL)
		list->head = list->tail = createNode(data);
	else
	{
		list->tail->next = createNode(data);
		list->tail = list->tail->next;		
	}
}

void printListHelper(node *head)
{
	if (head == NULL)
		return;

	printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
	printListHelper(head->next);
}

void printList(LinkedList *list)
{
	if (list == NULL || list->head == NULL)
	{
		printf("(empty list)\n");
		return;
	}

	printListHelper(list->head);
}

node *destroyListHelper(node *head)
{
	if (head == NULL)
		return NULL;

	destroyListHelper(head->next);
	free(head);

	return NULL;
}

LinkedList *destroyLinkedList(LinkedList *list)
{
	if (list == NULL)
		return NULL;

	destroyListHelper(list->head);
	free(list);
	return NULL;
}

int main(void)
{
	LinkedList *list = createList();

	for (int i = 0; i < 5; i++)
	{
		printf("Inserting %d\n", i+1);
		tailInsert(list, i+1);
	}
	
	printList(list);
	list = destroyLinkedList(list);

	return 0;
}
