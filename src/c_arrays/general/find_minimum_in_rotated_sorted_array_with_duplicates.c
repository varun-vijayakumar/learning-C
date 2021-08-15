/**
 * find minimum of a circular rotated sorted array with duplicates.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "common.h"


typedef enum bool_ {
    false = 0,
    true = 1,
} bool;

int findMinimum(int *a, int size) {
    int start = 0, end = size-1, next, prev, mid;
    while(start < end) {
        mid = start + (end - start) / 2;
        if (a[mid] == a[end]) {
            end--;
        } else if (a[mid] > a[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return a[end];
}

int main() {
    int a[6] = {3, 12, 12, 12, 1, 2};
    //int a[1] = {1};
    printf("minimum : %d\n", findMinimum(a, 6));
}
