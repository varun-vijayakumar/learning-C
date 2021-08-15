//
// Created by VARUN VIJAYAKUMAR on 5/23/20.
//
/**
 *
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

void print(int *nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%u ", nums[i]);
    }
    printf("\n");
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void square(int *nums, int numSize) {
    int temp;
    int i = 0;
    for (i = 0; i < numSize; i++) {
        temp = nums[i] * nums[i];
        nums[i] = temp;
    }
}

int main() {
    int array[5] = {-4,-1,0,3,10};
   square(array,5);
   print(array,5);
   selectionSort(array, 5);
   print(array,5);
   int i = 3;
   printf("%d %d\n", array[i--], array[i]);

}
