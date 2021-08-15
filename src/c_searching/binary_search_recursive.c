/**
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>
#include "quickSort.h"


void print(int *nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int binarySearch(int *a, int start, int end, int key) {
    if (start > end) {
        return -1; // or     if (mid <= start || mid >= end) return -1;
    }
    int mid = start + (end - start) / 2;


    if (a[mid] == key) {
        return mid;
    } else {
        if (a[mid] > key) {
            return binarySearch(a, start, mid-1, key);
        } else {
            return binarySearch(a, mid+1, end, key);
        }
    }
}

int main() {
    int a[8] = {5,2,6, 1, -1, 0, 11, 4};
    quickSort(a, 0, 7);
    print(a, 8);
    int key;
    while(1) {
        scanf("%d", &key);
        printf("%d :  %d \n", key, binarySearch(a, 0, 7, key));
    }
}