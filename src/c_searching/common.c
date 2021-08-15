#include "common.h"
#include "stdlib.h"
#include "stdio.h"

void print(int *nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
