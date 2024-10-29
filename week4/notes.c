#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} Person;

void change_age(Person *p, int age) {
    p->age = age;
}

Person* create_person(char *name, int age) {
    Person *p = malloc(sizeof(Person));
    p->name = "Joe";
    p->age = 420;
    return p;
}

int main() {
    // STRUCTS
    int arr[5] = {1, 2, 3, 4, 5};
    Person *p;
    int person_age = p->age; // (*p).age

    // DYNAMIC MEMORY ALLOCATION
    p = create_person("Joe", 420);
    printf("Name: %s, Age: %d\n", p->name, p->age);
    int SIZE = 5;
    int *arr = malloc(SIZE * sizeof(int));
    int *arr2 = calloc(SIZE, sizeof(int));

    // FREEING MEMORY
    free(p);

    return 0;
}
