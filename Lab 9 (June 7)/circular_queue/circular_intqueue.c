/* 
 * SYSC 2006 Winter 2018 Lab 9
 *
 * circular_intqueue.c - circular linked-list implementation of a queue.
 */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "circular_intqueue.h"

/* Return a pointer to a new intnode_t (a node in a singly-linked list).

   Parameter value: the integer to be stored in the node.
   Parameter next: a pointer to the node that the new node should point to.
   This pointer should be NULL if the new node is the last node in the 
   linked list.
   Terminate (via assert) if memory for the node cannot be allocated.
 */
intnode_t *intnode_construct(int value, intnode_t *next)
{
	intnode_t *p = malloc(sizeof(intnode_t));
	assert(p != NULL);
	p->value = value;
	p->next = next;
	return p;
}

/*---------------------------------------------------------- */

/* Return a pointer to a new, empty queue.
 * Terminate (via assert) if memory for the queue cannot be allocated.
 */
intqueue_t *intqueue_construct(void)
{
	intqueue_t *queue = malloc(sizeof(intqueue_t));
	assert(queue != NULL);

	queue->rear = NULL;
	queue->size = 0;
	return queue;
}

/* Return 
 if the specified queue contains no elements;
 * otherwise return false.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
_Bool intqueue_is_empty(const intqueue_t *queue)
{
	assert(queue != NULL);
	return queue->size == 0;
}

/* Return the number of elements stored in the specified queue.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
int intqueue_size(const intqueue_t *queue)
{
	assert(queue != NULL);
	return queue->size;
}

/* Print the contents of the specified queue to the console, 
 * from front to rear: [value0, value1, value3, ...]
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
void intqueue_print(const intqueue_t *queue)
{
	assert(queue != NULL);

	if (intqueue_is_empty(queue))
	{	// Handle an empty queue (no nodes).
		printf("[]");
		return;
	}

	/* In a circular linked list, the tail node (the node at the rear of the
	 * queue) points to the head node (the node at the front of the queue). 
	 * We don't need variable front, but it may make it easier to understand
	 * the code.
	 */
	intnode_t *front = queue->rear->next;
	intnode_t *current;

	printf("[");

	/* Print all the elements in the queue, except for the one at the rear. */
	for (current = front; current != queue->rear; current = current->next)
	{
		printf("%d, ", current->value);
	}

	/* Now print the element at the rear of the queue. */
	printf("%d]", current->value);
}

/*--------------------------------------------------------
 *
 * Solutions to Lab 9 exercises.
 */

/* Enqueue the specified value to the rear of a queue.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
void intqueue_enqueue(intqueue_t *queue, int value)
{
	intnode_t *p = intnode_construct(value, NULL);

	if (queue->rear == NULL)
	{	                                 //Same as queue->size == 0
		queue->rear = p;
		p->next = p;
	}
	else
	{
		p->next = queue->rear->next;	//p->next now points to the front of the queue
		queue->rear->next = p;	        //The old rear now points to p 
		queue->rear = p;	            //P is now the new rear
	}
	++queue->size;

}

/* Copy the value at the front of a queue to the variable pointed to by
 * parameter element, and return true.
 * Return false if the queue is empty.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
_Bool intqueue_front(const intqueue_t *queue, int *element)
{
	assert(queue != NULL);
	if (queue->rear == NULL)
	{	                                   //or queue->size = 0
		return false;
	}

	*element = queue->rear->next->value;	//This will work even if only one element since it would point to itself!
	return true;
}

/* Copy the value at the front of a queue to the variable pointed to by
 * parameter element, remove that value from the queue, and return true.
 * Return false if the queue is empty.
 * Parameter queue points to the queue.
 * Terminate (via assert) if queue is NULL.
 */
_Bool intqueue_dequeue(intqueue_t *queue, int *element)
{
	assert(queue != NULL);
	if (queue->size == 0)               //queue->rear == NULL does not work?
	{
		return false;
	}

	*element = queue->rear->next->value;
	intnode_t *delete = queue->rear->next;
	queue->rear->next = delete->next;
	free(delete);

	--queue->size;
	return true;
}
