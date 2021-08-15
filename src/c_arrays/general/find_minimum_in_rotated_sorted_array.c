/**
 * find minimum of a circular rotated sorted array without duplicates.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "common.h"




int findMinimum(int *a, int size) {
    int start = 0, end = size-1, next, prev, mid;
    int result;
    while(start <= end) {
        if (a[start] <= a[end]) {
            result = a[start];
            break;
        } else {
            mid = start + (end - start) / 2;
            next = (mid + 1 ) % size;
            prev = (mid + size - 1 ) % size;
            if (a[mid] < a[next] && a[mid] < a[prev]) {
                result = a[mid];
                break;
            } else if (a[mid] > a[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return result;
}

int main() {
    int a[6] = {11, 12, 13, 14, 5, 6};
    //int a[1] = {1};
    printf("minimum : %d\n", findMinimum(a, 6));
}
