/**
 * Divide and Conquer.
 * Get shortest array, sort and merge.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

typedef enum bool_ {
    false,
    true,
}bool;



void print(int *nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void sortedMerge(int *leftArray, int numLeft, int *rightArray, int numRight, int *array) {
    int i = 0, j = 0, k = 0;
    while (i < numLeft && j < numRight) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            k++;
            i++;
        } else {
            array[k] = rightArray[j];
            k++;
            j++;
        }
    }

    while(i < numLeft) {
        array[k] = leftArray[i];
        k++;
        i++;
    }

    while(j < numRight) {
        array[k] = rightArray[j];
        k++;
        j++;
    }
}
void mergeSort (int *a, int n) {
    if (n < 2) {
        return;
    }
    int middle = n / 2;
    int num_left = middle;
    int num_right = n - middle;
    int left[num_left];
    int right[num_right];
    int i = 0;
    for (i = 0; i < num_left; i++) {
        left[i] = a[i];
    }
    for (i = 0; i < num_right; i++) {
        right[i] = a[middle+i];
    }
    mergeSort(left, num_left);
    mergeSort(right, num_right);
    sortedMerge(left, num_left, right, num_right, a);
}

int main() {
    int a[6] = {5,2,6, 1, -1, 0};
    mergeSort(a, 6);
    print(a, 6);
}