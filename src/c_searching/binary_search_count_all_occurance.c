/**
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>
#include "quickSort.h"
#include "common.h"




int binarySearch(int *a, int size, int key, bool searchFirst) {
    int start = 0, end = size-1, result = -1;
    int mid = 0;
    while(start <= end) {
        mid = start + (end - start)/2 ;// (start+end)/2 is fine but start + (end - start)/2 will avoid overflow.
        if (a[mid] == key) {
            result = mid;
            if (searchFirst) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
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
    int firstOccurance, lastOccurance, count;
    while(1) {
        scanf("%d", &key);
        firstOccurance = binarySearch(a, 8, key, true);
        if (firstOccurance == -1) {
            count = 0;
        } else {
            lastOccurance = binarySearch(a, 8, key, false);
            count = lastOccurance - firstOccurance + 1;

        }
        printf("item : %d , count : %d \n", key, count);
    }
}