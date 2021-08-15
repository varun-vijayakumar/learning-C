/**
 * swap adjacent items.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

typedef enum bool_ {
    false,
    true,
}bool;

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int *nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void bubble_sort(int *a, int size) {
    int i,j = 0;
    int iMin = 0;
    bool swapped = false;
    for (i = 0; i < size; i++) {
        swapped = false;
        printf("---- : \n");
        for (j = 0; j < size-1; j++) { //size-i-1
            if (a[j] > a[j+1]) {
                swap(&a[j],&a[j+1]);
                swapped = true;
            }
                           
                print(a, 5);
                
        }
        printf("---- : \n");
        print(a, 5);
        if (!swapped)
            break;

    }
}

int main() {
    int a[5] = {5,2,6, 1, -1};
    bubble_sort(a, 5);
    //print(a, 5);
}