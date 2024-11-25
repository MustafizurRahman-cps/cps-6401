#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <cblas.h>

/*
  void diff2(double* u, int N, double dx, double* d2u)

  Computes a finite difference approximation for d^2u/dx^2

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  d2u: pointer to output array

  Outputs: 
  d2u: contains the second-order finite difference approximation

  Usage:
  gcc -o num2nd-order-derivative num2nd-order-derivative.c -lm -lblas
*/
void diff2(double* u, int N, double dx, double* d2u) {

  // Second-order finite difference for the interior points
  for (int i = 1; i < N; ++i) {
    d2u[i] = (u[i + 1] - 2 * u[i] + u[i - 1]) / (dx * dx);
  }

  // Boundary points using forward and backward differences
  d2u[0] = (u[2] - 2 * u[1] + u[0]) / (dx * dx);
  d2u[N] = (u[N] - 2 * u[N - 1] + u[N - 2]) / (dx * dx);
}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs: 
  u: pointer to array where values will be stored
  N: length of the array
  dx: the space step size

  Outputs: 
  u: contains data for a sin function
*/
void init(double* u, int N, double dx) {
  int i;
  for (i = 0; i <= N; ++i)
    u[i] = sin(i * dx);
}

/*
  int main(int argc, char* argv[])

  Function tests the accuracy of the second-order derivative approximation

  Inputs: argc should be 2
  argv[1] is the integer length of the data array
  
  Outputs: L2 error between exact and approximate second-order derivative
*/
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    double* u = (double*)malloc((N + 1) * sizeof(double));
    double* d2u = (double*)malloc((N + 1) * sizeof(double));
    double* errd2u = (double*)malloc((N + 1) * sizeof(double)); // calculating error
    double dx = M_PI / N;

    if (u == NULL || d2u == NULL || errd2u == NULL) {
        printf("Memory allocation failed.\n");
        free(u);
        free(d2u);
        free(errd2u);
        return 1;
    }

    init(u, N, dx);  

    // Compute the second-order finite difference approximation
    diff2(u, N, dx, d2u);
    
    // Calculate the error with respect to the exact second derivative, which is -sin(x) for f(x) = sin(x)
    for (int i = 0; i < N + 1; ++i) {
        errd2u[i] = -sin(i * dx) - d2u[i];
    }
    
    // Compute the L2 error norm
    double error_L2 = cblas_ddot(N + 1, errd2u, 1, errd2u, 1);
    printf("L2 error = %f\n", sqrt(error_L2));

    // Free allocated memory
    free(u);
    free(d2u);
    free(errd2u);

    return 0;
}

