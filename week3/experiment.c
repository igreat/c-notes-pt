#include <stdio.h>

int main() {
    double arr[5] = {1., 2., 3., 4., 5.};
    int* ptr = arr;
    for (int i = 0; i < 5; i++) {
        // jumps in double are 8 bytes
        printf("ptr = %p, value = %f\n", arr + i, *(arr + i));
        // int pointers are 4 bytes, hence I need to double the jump
        printf("ptr = %p, value = %f\n", ptr + 2 * i,
               *((double*)(ptr + 2 * i)));  // <-- notice 2*i
        printf("\n");
    }
    return 0;
}
