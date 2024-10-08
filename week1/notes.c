#include <stdio.h>

int main() {
    // INTEGER TYPES
    char letter = 'a';        // 8-bit integer
    short id = 1;             // 16-bit integer
    int age = 20;             // 32-bit integer
    long long big_age = 20;   // 64-bit integer, same as `long long int`
    // we can also add unsigned to the start of integer types
    unsigned int unsigned_age = 20;

    printf("letter: %d\n", id);

    // FLOATING POINT TYPES
    float height = 176.5;     // 32-bit float point number
    double height_d = 176.5;  // 64-bit float point number

    char name = 'a' + 4; // chars are just 8-bit integers, so we can do math on them

    int size = 4; // C does not store the size of the array on its own
    int heights[] = {170, 180, 190, 161}; 
    // We can do heights[10], C won't stop us from going out of bounds

    // algorithm to calculate the average height:
    int sum = 0;
    // for (initialization; condition; increment) { loop body }
    for (int i = 0; i < size; i++) { 
        sum += heights[i];
    }
    double average = (double)sum / size;

    printf("average of heights: %f\n", average);

    return 0;
}