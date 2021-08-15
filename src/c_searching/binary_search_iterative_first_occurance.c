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

int binarySearch(int *a, int size, int key) {
    int start = 0, end = size-1, result = -1;
    int mid = 0;
    while(start <= end) {
        mid = start + (end - start)/2 ;// (start+end)/2 is fine but start + (end - start)/2 will avoid overflow.
        if (a[mid] == key) {
            result = mid;
            end = mid -1;
        } else if (a[mid] < key) {
            start = mid + 1;
        } else  {
            end = mid -1;
        }
    }
    return result;
}

int main() {
    int a[8] = {5,2, 10, 10, 10, 10, 10, 14};
    quickSort(a, 0, 7);
    print(a, 8);
    int key;
    while(1) {
        scanf("%d", &key);
        printf("%d :  %d \n", key, binarySearch(a, 8, key));
    }
}