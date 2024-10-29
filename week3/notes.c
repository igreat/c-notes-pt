#include <stdio.h>

// - when we pass a pointer like &x, we are passing a copy of the address of x
//   to the function
// - by dereferencing the pointer, we can then modify the original variable
// - Note: ptr_x here lives inside the change_x stack frame, but *ptr_x, aka x,
//         lives inside the main stack frame
void change_x(int *ptr_x) { *ptr_x = 420; }

// - a function named swap that can swap two int variables
// void swap(...) { ... }
// a = 10
// b = 20
// swap(...)
// printf("a = %d, b = %d\n", a, b); // a = 20, b = 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // MEMORY LAYOUT

    /* Computer is fancy calculator (simplified view)
     *  - CPU (calculations)
     *  - RAM (memory)
     *
     * Values stored as bits (a byte is 8-bits)
     * - Addresses are used to retrieve those values
     * - How we interpret those bits matters, and depends on the type
     * - The same sequence of 32-bits means different things for different types
     *
     * Process memory layout (Stack, Heap, ..., Text):
     *  - Stack: Compile time, static memory allocation (int x = 10;)
     *  - Heap: Dynamic memory allocation (malloc, calloc, realloc, free)
     *  - ...
     *  - Text: Read only, contains the compiled code (instructions)
     */

    // POINTERS
    // play around using https://pythontutor.com/c.html#mode=edit
    // - function arguments are passed by value (copy)
    int x = 69;
    printf("x = %p\n", &x);
    change_x(&x);
    printf("x = %d\n", x);

    // SWAP
    int a = 10, b = 20;
    printf("a = %p, b = %p\n", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    // SCOPE
    int a = 10, b = 20;
    {
        int a = 0, b = 1;
        printf("a = %d, a = %d\n", a, b);
    }
    printf("a = %d, b = %d\n", a, b);

    // POINTER ARITHMETIC
    double arr[5] = {1., 2., 3., 4., 5.};
    double *ptr = arr; // &arr[0]
    printf("ptr = %p, value = %f\n", ptr + 0, (*(arr + 0)));
    printf("ptr = %p, value = %f\n", ptr + 1, (*(arr + 1)));
    printf("ptr = %p, value = %f\n", ptr + 2, (*(arr + 2)));
    printf("ptr = %p, value = %f\n", ptr + 3, (*(arr + 3)));
    printf("ptr = %p, value = %f\n", ptr + 4, (*(arr + 4)));
    printf("\n\n");
    printf("ptr = %p, value = %f\n", ptr + 0, 0[arr]);
    printf("ptr = %p, value = %f\n", ptr + 1, 1[arr]);
    printf("ptr = %p, value = %f\n", ptr + 2, 2[arr]);
    printf("ptr = %p, value = %f\n", ptr + 3, 3[arr]);
    printf("ptr = %p, value = %f\n", ptr + 4, 4[arr]);
    // int    4 bytes
    // double 8 bytes
    // 
    // arr[i] = *(arr + i)
    // i[arr] = *(i + arr) = *(arr + i)

    // DYNAMIC MEMORY ALLOCATION
    

    // FREEING MEMORY

    return 0;
}
