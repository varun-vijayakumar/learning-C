/**
 * Write a function that reverses a string. The input string is given as an array of characters char[].
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * You may assume all the characters consist of printable ascii characters.
*/


void swap (char *a, char *b) {
    char temp = *b;
    *b = *a;
    *a = temp;
}


void reverseString(char* s, int sSize){
    
    int i = 0;
    int mid = sSize / 2;
    for (i = 0 ; i < sSize; i++) {
        if (i== mid)
            break;
        swap(&s[i], &s[((sSize-1)-i) % sSize]);
    }
}