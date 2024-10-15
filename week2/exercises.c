#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Write a function that will compute the dot product of two arrays
   Assume that the arrays are of the same length
*/
int dot_product(int a[], int b[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

/* Write a function that tests if two strings are anagrams of each other
   An anagram is a string formed by rearranging the letters of a different
   string. Example: "cat" and "act" are anagrams of each other
*/
bool is_anagram(char a[], char b[]) {
    // alternative: represent each string's frequencies as two arrays of
    // size 26.
    //              freq_ids    = {'a', 'b', ..., 'z'}
    //              freq_counts = { 0,   0, ...,   0 }
    //              each frequency lookup is then a linear scan to find the
    //              correct index of freq_counts that corresponds to the
    //              character in freq_ids

    int freq_a[26] = {0};  // initialize all elements to 0
    int freq_b[26] = {0};  // initialize all elements to 0

    // (c - 'a'), 'a' -> 0, 'b' -> 1, ..., 'z' -> 25

    // accumulate frequencies for each string
    for (int i = 0; a[i] != '\0'; i++) {
        freq_a[a[i] - 'a']++;
    }
    for (int i = 0; b[i] != '\0'; i++) {
        freq_b[b[i] - 'a']++;
    }

    // compare frequencies for each character (as soon as we find a mismatch,
    // return false)
    for (char c = 'a'; c <= 'z'; c++) {
        if (freq_a[c - 'a'] != freq_b[c - 'a']) {
            return false;
        }
    }
    return true;
}

/* Write a function that will check if an array of integers contains a duplicate
   Constrains: all integers are between 0 and 1000 (inclusive)
*/
bool contains_duplicate(int a[], int size) {
    bool visited[1001] = {false};
    for (int i = 0; i < size; i++) {
        if (visited[a[i]]) {
            return true;
        }
        visited[a[i]] = true;
    }
    return false;
}

bool contains_duplicate_bruteforce(int a[], int size) {
    for (int i = 0; i < size; i++) {
        // j = i + 1 to ensure i < j, and we don't repeat say (i, j) and (j, i)
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                return true;
            }
        }
    }
    return false;
}

void test_dot_product() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    int size = 5;
    int expected = 55;
    int result = dot_product(a, b, size);
    printf("Expected: %d, Result: %d\n", expected, result);
}

void test_is_anagram() {
    char* a = "listen";
    char* b = "silent";
    bool expected = true;
    bool result = is_anagram(a, b);
    printf("Expected: %d, Result: %d\n", expected, result);
}

void test_contains_duplicate() {
    int a[] = {1, 2, 3, 4, 5};
    int size = 5;
    bool expected = false;
    bool result = contains_duplicate(a, size);
    printf("Expected: %d, Result: %d\n", expected, result);

    int b[] = {1, 2, 3, 4, 5, 1};
    size = 6;
    expected = true;
    result = contains_duplicate(b, size);
    printf("Expected: %d, Result: %d\n", expected, result);
}

int main() {
    test_dot_product();
    test_is_anagram();
    test_contains_duplicate();
}