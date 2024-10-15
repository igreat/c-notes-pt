#include <stdio.h>

// - when we pass a pointer like &x, we are passing a copy of the address of x
//   to the function
// - by dereferencing the pointer, we can then modify the original variable
// - Note: ptr_x here lives inside the change_x stack frame, but *ptr_x, aka x,
//         lives inside the main stack frame
void change_x(int *ptr_x) { *ptr_x = 420; }

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

    // DYNAMIC MEMORY ALLOCATION

    // FREEING MEMORY

    return 0;
}
