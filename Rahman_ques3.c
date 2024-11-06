
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20

int main() {
    int number[SIZE];
    int i = 0;
    double sum = 0, mean, std_dev = 0;
    int frequency[101] = {0}; // Assuming scores are from 0 to 100
    int mode = 0, max_frequency = 0;

    FILE* in_file = fopen("scores-data.txt", "r");
    if (!in_file) {
        printf("oops, file can't be read\n");
        exit(-1);
    }

    // Read data from file
    while (fscanf(in_file, "%d", &number[i]) == 1) {
        sum += number[i];
        frequency[number[i]]++;
        if (frequency[number[i]] > max_frequency) {
            max_frequency = frequency[number[i]];
            mode = number[i];
        }
        i++;
    }
    fclose(in_file);

    mean = sum / SIZE;

    // Calculate standard deviation
    for (i = 0; i < SIZE; i++) {
        std_dev += pow(number[i] - mean, 2);
    }
    std_dev = sqrt(std_dev / SIZE);

    // Print the results
    printf("Mean: %lf\n", mean);
    printf("Mode: %d\n", mode);
    printf("Standard Deviation: %lf\n", std_dev);

    return 0;
}
