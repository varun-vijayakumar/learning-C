/**
 * Find min in the array for every iteration.
 * Push swap current with min
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>

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

void selection_sort(int *a, int size) {
    int i,j = 0;
    int iMin = 0;
    int temp = 0;

    for (i = 0; i < size-1; i++) {
        iMin = i;
        for (j = i+1; j < size; j++) {
            if (a[j] < a[iMin]) {
                iMin = j;
            }
        }
        swap(&a[i],&a[iMin]);
        print(a, 5);
    }
}

int main() {
    int a[5] = {5,2,6, 1, -1};
    clock_t start, end;
    start = clock();
    selection_sort(a, 5);
    end = clock();
    printf("Time taken : %f\n", (double)end-start / CLOCKS_PER_SEC);
    //print(a, 5);
}