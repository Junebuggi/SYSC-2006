/* SYSC 2006 Winter 2018 Lab 6
 *
 * array_list.h 
 *
 * Header file for a prototype of a dynamically allocated, fixed-capacity 
 * list that supports a subset of the operations provided by Python's 
 * list class.
 */ 

#include <stdbool.h>

typedef struct {
    int     *elems;    // Pointer to backing array.
    int     capacity;  // Maximum number of elements in the list.
    int     size; 	   // Current number of elements in the list.
} intlist_t;

intlist_t  *intlist_construct(int capacity);
void    intlist_destroy(intlist_t *list);

int     intlist_size(const intlist_t *list);
int     intlist_capacity(const intlist_t *list);

_Bool   intlist_append(intlist_t *list, int element);
int     intlist_get(const intlist_t *list, int index);
int     intlist_set(intlist_t *list, int index, int element);
void    intlist_removeall(intlist_t *list);

void    intlist_print(const intlist_t *list);
