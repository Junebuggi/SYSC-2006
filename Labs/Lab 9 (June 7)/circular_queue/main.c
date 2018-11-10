/* SYSC 2006 Winter 2018 Lab 9 */

/* Test harness to exercise the functions in the circular_intqueue.c module.
   Version 1.00 - dlb 
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "circular_intqueue.h"

void print_bool(_Bool value)
{
    if (value) {
        printf("true");
    } else {
        printf("false");
    }
}


/* Tests for Exercise 1. */

void test_enqueue(void)
{
    printf("=== Test 1: Testing intqueue_enqueue ===\n\n");
    printf("Calling intqueue_construct to create an empty queue\n");
    intqueue_t *queue = intqueue_construct();

    printf("Calling intqueue_enqueue to enqueue 40\n");
    intqueue_enqueue(queue, 40);
    printf("Expected queue size: 1\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [40]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_enqueue to enqueue 30\n");
    intqueue_enqueue(queue, 30);
    printf("Expected queue size: 2\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [40, 30]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_enqueue to enqueue 20\n");
    intqueue_enqueue(queue, 20);
    printf("Expected queue size: 3\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [40, 30, 20]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");
}

/* Tests for Exercise 2. */

void test_front(void)
{
    int elem;
    _Bool success;

    printf("=== Test 2: Testing intqueue_front ===\n\n");
    printf("Calling intqueue_construct to create an empty queue\n");
    intqueue_t *queue = intqueue_construct();

    printf("Calling intqueue_front\n");
    success = intqueue_front(queue, &elem);

    printf("Expected return value: false\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n\n");

    printf("Calling intqueue_enqueue to enqueue 40\n");
    intqueue_enqueue(queue, 40);
    printf("Queue is: ");
    intqueue_print(queue);
    printf("\n");

    printf("Calling intqueue_front\n");
    success = intqueue_front(queue, &elem);
    printf("Expected return value: true\n");
    printf("Actual return value:   ");
    print_bool(success);
	printf("\n");
    printf("Value retrieved by intqueue_front - expected value: 40\n");
    printf("Value retrieved by intqueue_front - actual value:   ");
    printf("%d\n", elem);
    printf("Expected queue size: 1\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [40]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_enqueue to enqueue 30\n");
    intqueue_enqueue(queue, 30);
    printf("Queue is: ");
    intqueue_print(queue);
    printf("\n");

    printf("Calling intqueue_front\n");
    success = intqueue_front(queue, &elem);
    printf("Expected return value: true\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n");
    printf("Value retrieved by intqueue_front - expected value: 40\n");
    printf("Value retrieved by intqueue_front - actual value:   ");
    printf("%d\n", elem);
    printf("Expected queue size: 2\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [40, 30]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_enqueue to enqueue 20\n");
    intqueue_enqueue(queue, 20);
    printf("Queue is: ");
    intqueue_print(queue);
    printf("\n");

    printf("Calling intqueue_front\n");
    success = intqueue_front(queue, &elem);
    printf("Expected return value: true\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n");
    printf("Value retrieved by intqueue_front - expected value: 40\n");
    printf("Value retrieved by intqueue_front - actual value:   ");
    printf("%d\n", elem);
    printf("Expected queue size: 3\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [40, 30, 20]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");
}

/* Tests for Exercise 3
. */
void test_dequeue(void)
{
    int elem;
    _Bool success;

    printf("=== Test 3: Testing intqueue_dequeue ===\n\n");
    printf("Calling intqueue_construct to create an empty queue\n");
    intqueue_t *queue = intqueue_construct();

    printf("Calling intqueue_dequeue\n");
    success = intqueue_dequeue(queue, &elem);
    printf("Expected return value: false\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n");
    printf("Expected queue size: 0\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: []\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_enqueue to enqueue 40, 30, 20\n");
    intqueue_enqueue(queue, 40);
    intqueue_enqueue(queue, 30);
    intqueue_enqueue(queue, 20);
    printf("Queue is: ");
    intqueue_print(queue);
    printf("\n");

    printf("Calling intqueue_dequeue\n");
    success = intqueue_dequeue(queue, &elem);
    printf("Expected return value: true\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n");
    printf("Value removed by intqueue_dequeue - expected value: 40\n");
    printf("Value removed by intqueue_dequeue - actual value:   ");
    printf("%d\n", elem);
    printf("Expected queue size: 2\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [30, 20]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_dequeue\n");
    success = intqueue_dequeue(queue, &elem);
    printf("Expected return value: true\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n");
    printf("Value removed by intqueue_dequeue - expected value: 30\n");
    printf("Value removed by intqueue_dequeue - actual value:   ");
    printf("%d\n", elem);
    printf("Expected queue size: 1\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: [20]\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_dequeue\n");
    success = intqueue_dequeue(queue, &elem);
    printf("Expected return value: true\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n");
    printf("Value removed by intqueue_dequeue - expected value: 20\n");
    printf("Value removed by intqueue_dequeue - actual value:   ");
    printf("%d\n", elem);
    printf("Expected queue size: 0\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: []\n");
    printf("Actual queue:   ");
    intqueue_print(queue);
    printf("\n\n");

    printf("Calling intqueue_dequeue\n");
    success = intqueue_dequeue(queue, &elem);
    printf("Expected return value: false\n");
    printf("Actual return value:   ");
    print_bool(success);
    printf("\n");
    printf("Expected queue size: 0\n");
    printf("Actual queue size:   %d\n", intqueue_size(queue));
    printf("Expected queue: []\n");
    printf("Actual queue:   ");
	intqueue_print(queue);
    printf("\n\n");
}

int main(void)
{
    printf("Running test harness for SYSC 2006 W18 Lab 9\n\n");

    test_enqueue();
    test_front();
    test_dequeue();
}
