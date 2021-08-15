/**
 * find an element in a circular rotated sorted array without duplicates is given
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "common.h"




int findElement(int *a, int size, int key) {
    int start = 0, end = size - 1, mid;
    while(start <= end) {
        mid = start+ (end-start) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] <= a[end]) {
            if (key > a[mid] && key <= a[end]) {
                start = mid+1;
            } else {
                end = mid - 1;
            }
        } else if (a[start] <= a [mid]) {
            if (key >= a[start] && key < a[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    int a[7] = {4,5,6,7,0,1,2};
    printArray(a, 7);
    int key;
    while(1) {
        scanf("%d", &key);
        printf("%d :  %d \n", key, findElement(a, 7, key));
    }
}