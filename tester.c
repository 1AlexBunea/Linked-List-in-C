#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedListHeader.h"


void linked_list_remove_tests(struct linked_list *this_linked_list, int *testNumber) {
    printf("linked_list_remove() test\n");
    linked_list_remove(this_linked_list, 2);
    bool expectedBool = (linked_list_size(this_linked_list) == 3);
    if (expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;
    linked_list_remove(this_linked_list, 0);
    expectedBool = (linked_list_index_of(this_linked_list, 20) == -1);
    if (expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;
    linked_list_remove(this_linked_list, 1);
    expectedBool = (linked_list_size(this_linked_list) == 1);
    if (expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;
}

/**
 * tests for linked_list_set() function
*/
void linked_list_set_tests(struct linked_list *this_linked_list, int *testNumber) {
    printf("linked_list_set() tests\n");
    linked_list_set(this_linked_list, 0, 20);
    bool expectedBool = (linked_list_index_of(this_linked_list, 20) == 0);
    if (expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;
    linked_list_set(this_linked_list, linked_list_size(this_linked_list) - 1, 0);
    expectedBool = (linked_list_index_of(this_linked_list, 0) == 3);
    if (expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;
    linked_list_set(this_linked_list, 1, -30);
    expectedBool = (linked_list_index_of(this_linked_list, -30) == 1);
    if (expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;

}


/**
 * tests for linked_list_index_of() function
*/
void linked_list_index_Of_tests(struct linked_list *this_linked_list, int *testNumber) {
    printf("linked_list_index_Of() tests\n");
    int index = linked_list_index_of(this_linked_list, 4);
    bool actualBool = true;
    bool expectedBool = (index == 0);
    if (actualBool && expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;
    index = linked_list_index_of(this_linked_list, 7);
    expectedBool = (index == 3);
    if (actualBool && expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;
    index = linked_list_index_of(this_linked_list, 8);
    expectedBool = (index == -1);
    if (actualBool && expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }   
    *testNumber += 1;

}

/**
 * runs tests for the linked_list_add() method
*/
void linked_list_add_tests(struct linked_list *this_linked_list, int *testNumber) {
    printf("linked_list_add() tests\n");
    linked_list_add(this_linked_list, 4);

    bool actualBool = true;
    bool expectedBool = (linked_list_size(this_linked_list) == 1);
    if (actualBool && expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }
    *testNumber += 1;

    linked_list_add(this_linked_list, 5);

    expectedBool = (linked_list_size(this_linked_list) == 2);
    if (actualBool && expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }
    *testNumber += 1;

    linked_list_add(this_linked_list, 6);
    linked_list_add(this_linked_list, 7);
    expectedBool = (linked_list_size(this_linked_list) == 4);
    if (actualBool && expectedBool) {
        printf("test %d passed\n", *testNumber);
    } else {
        printf("test %d failed\n", *testNumber);
    }
    *testNumber += 1;
}

    void empty_list_tests(struct linked_list *this_linked_list, int *testNumber) {

        for (int i = 0; i < 25; i++) {
            linked_list_add(this_linked_list, i%7);
        }
        empty_list(this_linked_list);
        bool expectedBool = (linked_list_size(this_linked_list) == 0);
        if (expectedBool) {
            printf("test %d passed\n", *testNumber);
        } else {
            printf("test %d failed\n", *testNumber);
        }
        *testNumber += 1;

        for (int i = -10; i < 3; i++) {
            linked_list_add(this_linked_list, i);
        }
        empty_list(this_linked_list);
        expectedBool = (linked_list_size(this_linked_list) == 0);
        if (expectedBool) {
            printf("test %d passed\n", *testNumber);
        } else {
            printf("test %d failed\n", *testNumber);
        }
        *testNumber += 1;
        for (int i = 0; i < 600000; i++) {
            linked_list_add(this_linked_list, i);
        }
        empty_list(this_linked_list);
        expectedBool = (linked_list_size(this_linked_list) == 0);
        if (expectedBool) {
            printf("test %d passed\n", *testNumber);
        } else {
            printf("test %d failed\n", *testNumber);
        }
        *testNumber += 1;

    }

int main() {

    int testNumber = 1;

    struct linked_list *this_linked_list = linked_list_create();
    
    linked_list_add_tests(this_linked_list, &testNumber);
    toString(this_linked_list);
    
    linked_list_index_Of_tests(this_linked_list, &testNumber);
    toString(this_linked_list);

    linked_list_set_tests(this_linked_list, &testNumber);
    toString(this_linked_list);

    linked_list_remove_tests(this_linked_list, &testNumber);
    toString(this_linked_list);

    empty_list_tests(this_linked_list, &testNumber);
    toString(this_linked_list);

    return EXIT_SUCCESS;
}
