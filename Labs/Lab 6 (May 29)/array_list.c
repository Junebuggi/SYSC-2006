/* SYSC 2006 Winter 2018 Lab 6
 *
 * array_list.c 
 *
 * Prototype of a dynamically allocated, fixed-capacity list that supports a 
 * subset of the operations provided by Python's list class.
 */ 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array_list.h"

/* Construct a new, empty list, and return a pointer to it
 * Parameter capacity is the # of elements that can be stored in the list.
 * Terminate the program via assert if capacity is <= 0.
 * Terminate the program via assert if memory for the list cannot be 
 * allocated from the heap.
 */
intlist_t *intlist_construct(int capacity)
{
    // Note - this is an incomplete function definition.
    // You must modify the function so that it correctly implements all 
    // of the requirements listed in the header comment. 
	assert(capacity > 0);
    intlist_t *list = malloc(sizeof(intlist_t));
	assert(list != NULL);
    list->capacity = capacity;
    list->size = 0;
   
	list->elems = malloc(sizeof(int) * capacity);
	for (int i = 0; i < capacity; ++i) {
		list->elems[i] = 0;
    }
	
    return list;
}

/* Destroy the list pointed to by parameter list, deallocating all memory 
 * that was allocated from the heap.
 * Terminate the program via assert if list is NULL.
 */
void intlist_destroy(intlist_t *list)
{
    assert(list != NULL);
    free(list->elems);  /* Return the array to the heap. */
    free(list);         /* Return the structure to the heap. */
}

/* Print the list pointed to by parameter list to the console.
 * Terminate the program via assert if list is NULL.
 */
void intlist_print(const intlist_t *list)
{
	assert(list != NULL);
	printf("[");
	for (int i = 0; i < list->size; ++i) {
   		if(i < list->size - 1){
			printf("%i ", list->elems[i]);
		}
		else{
			printf("%i", list->elems[i]);
		}
	}
    
	printf("]\n");
    
	return;
}

/* Insert element at the end of the list pointed to by list.
 * Return true if element is appended; otherwise return false
 * (which indicates that the list is full.)
 * Terminate the program via assert if list is NULL.
 */
_Bool intlist_append(intlist_t *list, int element)
{
	assert(list != NULL);
	if(list->size < list->capacity){
		list->elems[list->size] = element;
		++list->size;
        
		return true;
	}
    
    return false;
}

/* Return the maximum number of integers that can be stored in the list 
 * pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int intlist_capacity(const intlist_t *list)
{
	assert(list != NULL);
	
	return list->capacity;
}

/* Return the number of integers in the list pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int intlist_size(const intlist_t *list)
{
    assert(list != NULL);
    
	return list->size;
}

/* Return the element located at the specified index, in the list
 * pointed to by parameter list. 
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. intlist_size() - 1.
 */
int intlist_get(const intlist_t *list, int index)
{
    assert(list != NULL);
    
	return list->elems[index];
}

/* Store element at the specified index, in the list pointed to by 
 * parameter list. Return the integer that was previously 
 * stored at that index.
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. intlist_size() - 1.
 */
int intlist_set(intlist_t *list, int index, int element)
{
    assert(list != NULL);
	assert(index < list->size);
	int temp = list->elems[index];
	list->elems[index] = element;
    
	return temp;

}

/* Empty the list pointed to by parameter list.
 * Memory allocated to the list is not freed, so the emptied list can 
 * continue to be used.
 * Terminate the program via assert if list is NULL.
 */
void intlist_removeall(intlist_t *list)
{
	assert(list != NULL);
    
	for (int i = 0; i < list->size; ++i) {
		list->elems[i] = 0;
	}
    
	list->size = 0;
}
