/*
 * Swap_two_num.c
 * Demonstrates different ways to swap two numbers in C
 * 1. Using a temporary variable
 * 2. Without a temporary variable (arithmetic)
 * 3. Using bitwise XOR
 * 4. Using a macro
 */

#include <stdio.h>

// 1. Swap using a temporary variable
void swap_temp(int *a, int *b) {
    // Store value of *a in temp
    int temp = *a;
    // Assign value of *b to *a
    *a = *b;
    // Assign value of temp (original *a) to *b
    *b = temp;
}

// 2. Swap without a temporary variable (arithmetic method)
void swap_arithmetic(int *a, int *b) {
    // Be careful: This method can cause overflow if a and b are large
    *a = *a + *b; // a now holds sum of both
    *b = *a - *b; // b is now original a
    *a = *a - *b; // a is now original b
}

// 3. Swap using bitwise XOR operator
void swap_xor(int *a, int *b) {
    // This method does not use extra memory and avoids overflow
    if (a != b) { // Ensure pointers are not the same
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

// 4. Swap using a macro
#define SWAP_MACRO(x, y) \
    do { \
        int temp = x; \
        x = y; \
        y = temp; \
    } while(0)

int main() {
    int x = 10, y = 20;

    printf("Original x = %d, y = %d\n", x, y);

    // Using temporary variable
    swap_temp(&x, &y);
    printf("After swap_temp: x = %d, y = %d\n", x, y);

    // Swap back using arithmetic
    swap_arithmetic(&x, &y);
    printf("After swap_arithmetic: x = %d, y = %d\n", x, y);

    // Swap again using XOR
    swap_xor(&x, &y);
    printf("After swap_xor: x = %d, y = %d\n", x, y);

    // Swap back using macro
    SWAP_MACRO(x, y);
    printf("After SWAP_MACRO: x = %d, y = %d\n", x, y);

    return 0;
}
