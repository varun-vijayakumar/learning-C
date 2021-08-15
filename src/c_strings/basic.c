
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LL1_LEN 2
#define LL2_LEN 3
typedef enum bool_ {
    false = 0,
    true = 1,
} bool;


void swap (char *a, char *b) {
    printf("a : %c b : %c\n", *a, *b);
    char temp = *b;
    *b = *a;
    *a = temp;
        printf("a : %c b : %c\n", *a, *b);

}

int main() {
    char String[] = "t";
    int len = strlen(String);
    int i = 0;
    int mid = len / 2;
    for (i = 0 ; i < len; i++) {
       // printf("%c ", String[((len-1)-i) % len]);
        if (i== mid)
            break;
        swap(&String[i], &String[((len-1)-i) % len]);
    }
    printf("Reversed : %s\n", String);
}
