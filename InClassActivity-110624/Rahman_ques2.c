
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - (*(int*)b));
}

int main() {
    int scores[] = {10, 7, 5, 9, 10}; // Example scores
    int n = sizeof(scores) / sizeof(scores[0]);
    double sum = 0, mean, median, std_dev = 0;
    int frequency[11] = {0}; // Assuming scores are from 0 to 10
    int mode = 0, max_frequency = 0;

    // Calculate sum and frequency of each score
    for (int i = 0; i < n; i++) {
        sum += scores[i];
        frequency[scores[i]]++;
        if (frequency[scores[i]] > max_frequency) {
            max_frequency = frequency[scores[i]];
            mode = scores[i];
        }
    }

    mean = sum / n;

    // Calculate standard deviation
    for (int i = 0; i < n; i++) {
        std_dev += pow(scores[i] - mean, 2);
    }
    std_dev = sqrt(std_dev / n);

    // Sort the array to find median
    qsort(scores, n, sizeof(int), compare);
    if (n % 2 != 0)
        median = scores[n/2]; // If odd, middle element is median
    else
        median = (scores[n/2 - 1] + scores[n/2]) / 2.0; // If even, average of two middle elements

    // Print the results
    printf("Mean: %lf\n", mean);
    printf("Median: %lf\n", median);
    printf("Mode: %d\n", mode);
    printf("Standard Deviation: %lf\n", std_dev);

    return 0;
}
