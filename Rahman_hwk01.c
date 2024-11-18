#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 30

int main() {
    // Data provided by the user
    int number[SIZE] = {0, 15, 20, 1, 100, 0, 60, 1, 75, 29, 1, 69, 100, 91, 56, 1, 89, 0, 98, 1, 45, 100, 0, 78, 59, 11, 0, 0, 1, 100};
    int i;
    int frequency[101] = {0}; // Assuming scores are between 0 and 100

    // Calculate the frequency of each score
    for (i = 0; i < SIZE; i++) {
        frequency[number[i]]++;
    }

    // Find the highest frequency
    int max_frequency = 0;
    for (i = 0; i < 101; i++) {
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
        }
    }

    // Find and print all modes
    printf("Mode(s): ");
    int mode_count = 0;
    for (i = 0; i < 101; i++) {
        if (frequency[i] == max_frequency && max_frequency > 1) {
            printf("%d (appears %d times)\n", i, max_frequency);
            mode_count++;
        }
    }

    if (mode_count == 0) {
        printf("No mode, all elements are unique.\n");
    }

    // Calculate the mean
    double sum = 0;
    for (i = 0; i < SIZE; i++) {
        sum += number[i];
    }
    double mean = sum / SIZE;
    printf("Mean: %lf\n", mean);

    // Calculate the standard deviation
    double std_dev = 0;
    for (i = 0; i < SIZE; i++) {
        std_dev += pow(number[i] - mean, 2);
    }
    std_dev = sqrt(std_dev / SIZE);
    printf("Standard Deviation: %lf\n", std_dev);

    return 0;
}

