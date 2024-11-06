
#include <stdio.h>

int main() {
    int numbers[10] = {12, 7, 19, 3, 25, 18, 5, 21, 9, 14}; // Example array of numbers
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
