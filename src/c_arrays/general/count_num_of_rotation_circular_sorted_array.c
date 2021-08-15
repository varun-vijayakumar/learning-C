/**
 * find number of circular rotation when a sorted array without duplicates is given
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "common.h"




int countRotation(int *a, int size) {
    int start = 0, end = size-1, next, prev, mid;
    while(start <= end) {
        if (a[start] <= a[end]) {
            return start;
        } else {
            mid = (start + end) / 2;
            next = (mid + 1) % size;
            prev = (mid + size - 1) % size;
            if (a[mid] <= a[next] && a[mid] <= a[prev]) {
                return mid;
            } else if (a[mid] < a[end]) {
                end = mid - 1;
            } else if (a[mid] > a[start]) {
                start = mid + 1;
            }
        }
        
    }
    return -1;
}

int main() {
    //int a[6] = {11, 12, 13, 4, 5, 6};
    int a[1] = {1};
    int key;
    int firstOccurance, lastOccurance, count;
    printf("number of rotations : %d\n", countRotation(a, 1));
}