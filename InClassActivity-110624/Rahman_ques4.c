
#include <stdio.h>

int main() {
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array of numbers
    int *ptr = numbers; // Pointer to the array
    int max = *ptr; // Initialize max to the first element

    for (int i = 1; i < 10; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

    printf("The maximum integer is: %d\n", max);
    return 0;
}
