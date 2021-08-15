//
// Created by VARUN VIJAYAKUMAR on 5/23/20.
//
/**
 * Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.



Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]


Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9
 */

void print(int *nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%u ", nums[i]);
    }
    printf("\n");
}
void duplicateZeros(int* arr, int arrSize){
    int i = 0;
    for (i = arrSize-1; i >= 0; i--) {
        if (arr[i] == 0) {
            arr[i+1] = arr[i];
        }
    }
}

int main() {
    int array[5] = {-4,-1,0,3,10};
    duplicateZeros(array,5);
    print(array,5);
}
