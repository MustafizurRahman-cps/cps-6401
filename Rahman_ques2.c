
#include <stdio.h>
#include <math.h>

int main() {
    int x[5] = {10, 7, 5, 9, 10}; // Example scores
    int n = 5;
    double sum = 0, mean, std_dev = 0;
    int frequency[11] = {0}; // Assuming scores are between 0 and 10
    int mode = 0, max_frequency = 0;

    // Calculate sum and frequency of each score
    for (int i = 0; i < n; i++) {
        sum += x[i];
        frequency[x[i]]++;
        if (frequency[x[i]] > max_frequency) {
            max_frequency = frequency[x[i]];
            mode = x[i];
        }
    }

    mean = sum / n;

    // Calculate standard deviation
    for (int i = 0; i < n; i++) {
        std_dev += pow(x[i] - mean, 2);
    }
    std_dev = sqrt(std_dev / n);

    // Print the results
    printf("Mean: %lf\n", mean);
    printf("Mode: %d\n", mode);
    printf("Standard Deviation: %lf\n", std_dev);

    return 0;
}
