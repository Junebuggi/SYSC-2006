/* SYSC 2006 Winter 2018 Lab 11 */

/* Test harness to exercise the functions in the sl_list.c module.
   Version 1.02 - dlb 
 */

#include <assert.h>             // assert
#include <stdlib.h>             // malloc, free
#include <stdbool.h>
#include <stdio.h>              // printf

#include "sl_list.h"

/* Returns a pointer to the head of a new linked list
   containing 10 nodes:

   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
 */
intnode_t *setup(void)
{
    intnode_t *head = NULL;     // start with an empty list
    head = push(head, 9);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 6);
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    return head;
}

/* Free all the nodes in the linked list pointed to by head. */
void teardown(intnode_t *head)
{
    intnode_t *current;
    intnode_t *node_to_delete;

    for (current = head; current != NULL;) {
        node_to_delete = current;
        current = current->next;
        free(node_to_delete);
    }
}


/* Tests for Exercise 1. */

void test_add(void)
{
    printf("=== Exercise 1: Testing add ===\n\n");

    intnode_t *head = NULL;    // An empty linked list.

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 10 at index 0.\n");
    head = add(head, 10, 0);
    printf("Expected list after add: 10\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 10 */
    head = intnode_construct(10, NULL);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 20 value at index 0.\n");
    head = add(head, 20, 0);
    printf("Expected list after add: 20 -> 10\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 20 -> 10 */
    head = intnode_construct(10, NULL);
    head = intnode_construct(20, head);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 30 at index 1.\n");
    head = add(head, 30, 1);
    printf("Expected list after add: 20 -> 30 -> 10\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 20 -> 30 -> 10 */
    head = intnode_construct(10, NULL);
    head = intnode_construct(30, head);
    head = intnode_construct(20, head);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 40 at index 3.\n");
    head = add(head, 40, 3);
    printf("Expected list after add: 20 -> 30 -> 10 -> 40\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 20 -> 30 -> 10 -> 40 */
    head = intnode_construct(40, NULL);
    head = intnode_construct(10, head);
    head = intnode_construct(30, head);
    head = intnode_construct(20, head);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 50 at index 3.\n");
    head = add(head, 50,3);
    printf("Expected list after add: 20 -> 30 -> 10 -> 50 -> 40\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);
}

/* Tests for Exercise 2. */

void test_every_other(void)
{
    printf("=== Exercise 2: Testing every_other ===\n\n");

    // Test empty list.
    intnode_t *head = NULL;
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: empty list\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with one node.
    head = push(NULL, 1);
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 1\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with two nodes.
    head = push(NULL, 2);
    head = push(head, 1);
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 1\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with an odd number of nodes.
    head = setup();             // head points to a list with 9 nodes
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 1 -> 3 -> 5 -> 7 -> 9\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with an even number of nodes.
    head = setup();
    head = push(head, 0);       // Now the list has 10 nodes
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 0 -> 2 -> 4 -> 6 -> 8\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);
}

int main(void)
{
    printf("Running test harness for SYSC 2006 Winter 18 Lab 11\n\n");

    test_add();
    test_every_other();
}
