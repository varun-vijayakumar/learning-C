//
// Created by VARUN VIJAYAKUMAR on 5/22/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int count_digits(int num) {
    int count = 1;
    int rem = num;
    while(rem >= 10) {
        rem = rem / 10;
        count++;
    }
    return count;
}

int findNumbers(int* nums, int numsSize) {
    int count = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (!(count_digits(nums[i]) % 2)) {
            count++;
        }
    }
    return count;
}

int main() {
    int array[4] = {555,901,482,1771};
    printf("%d\n", findNumbers(array,4));
}