#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/*
  void forward_diff(double* u, int N, double dx, double* du)

  Computes a forward finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the forward finite difference approximation
*/
void forward_diff(double* u, int N, double dx, double* du) {
  for (int i = 0; i < N; ++i) {
    du[i] = (u[i + 1] - u[i]) / dx;
  }
}

/*
  void central_diff(double* u, int N, double dx, double* du)

  Computes a central finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the central finite difference approximation
*/
void central_diff(double* u, int N, double dx, double* du) {
  for (int i = 1; i < N; ++i) {
    du[i] = (u[i + 1] - u[i - 1]) / (2 * dx);
  }
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
  for (int i = 0; i <= N; ++i) {
    u[i] = sin(i * dx);
  }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    double a = 0.0;
    double b = 2 * PI;
    double h = (b - a) / N;

    printf("Step size h = %lf\n", h);

    // Allocate memory for arrays
    double* u = (double*)malloc((N + 1) * sizeof(double));
    double* du_forward = (double*)malloc(N * sizeof(double));
    double* du_central = (double*)malloc((N + 1) * sizeof(double));
    if (u == NULL || du_forward == NULL || du_central == NULL) {
        printf("Memory allocation failed.\n");
        free(u);
        free(du_forward);
        free(du_central);
        return 1;
    }

    // Initialize the array with sin values
    init(u, N, h);

    // Compute the forward difference approximation
    forward_diff(u, N, h, du_forward);
    printf("\nForward Difference Approximation:\n");
    for (int i = 0; i < N; ++i) {
        printf("f'(%lf) ~ %lf\n", a + i * h, du_forward[i]);
    }

    // Compute the central difference approximation
    central_diff(u, N, h, du_central);
    printf("\nCentral Difference Approximation:\n");
    for (int i = 1; i < N; ++i) {
        printf("f'(%lf) ~ %lf\n", a + i * h, du_central[i]);
    }

    // Free allocated memory
    free(u);
    free(du_forward);
    free(du_central);

    return 0;
}


