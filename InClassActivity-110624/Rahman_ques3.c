
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20

int compare(const void *a, const void *b) {
    return (*(int*)a - (*(int*)b));
}

int main() {
    int scores[SIZE];
    int i = 0;
    double sum = 0, mean, median, std_dev = 0;
    int frequency[101] = {0}; // Assuming scores are from 0 to 100
    int mode = 0, max_frequency = 0;

    FILE* in_file = fopen("scores-data.txt", "r");
    if (!in_file) {
        printf("oops, file can't be read\n");
        exit(-1);
    }

    while (fscanf(in_file, "%d", &scores[i]) == 1) {
        sum += scores[i];
        frequency[scores[i]]++;
        if (frequency[scores[i]] > max_frequency) {
            max_frequency = frequency[scores[i]];
            mode = scores[i];
        }
        i++;
    }
    fclose(in_file);

    mean = sum / SIZE;

    // Calculate standard deviation
    for (i = 0; i < SIZE; i++) {
        std_dev += pow(scores[i] - mean, 2);
    }
    std_dev = sqrt(std_dev / SIZE);

    // Sort the array to find median
    qsort(scores, SIZE, sizeof(int), compare);
    if (SIZE % 2 != 0)
        median = scores[SIZE/2];
    else
        median = (scores[SIZE/2 - 1] + scores[SIZE/2]) / 2.0;

    // Print the results
    printf("Mean: %lf\n", mean);
    printf("Median: %lf\n", median);
    printf("Mode: %d\n", mode);
    printf("Standard Deviation: %lf\n", std_dev);

    return 0;
}
