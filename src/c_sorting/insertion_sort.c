/**
 * shift and insert by comparing.
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

void insertion_sort(int *a, int size) {
    int i,j = 0;
    int value = 0;
    int current = 0;
    for (i = 1; i < size; i++) {
        value = a[i];
        current = i;
        printf("---iter : %d current : %d------\n", i, value);
        while(current > 0 && a[current-1] > value) {
            swap(&a[current], &a[current-1]);
            current = current-1;
            //print(a,5);
        }
        print(a,5);
        printf("---------\n");
        a[current] = value;
        print(a,5);
    }
}

int main() {
    int a[5] = {5,2,6, 1, -1};
    insertion_sort(a, 5);
}