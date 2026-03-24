#include <stdio.h>

int main()
{
    int n, i, j, k;
    float A[10][10], L[10][10], U[10][10];
    float B[10], Y[10], X[10], sum;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter matrix B:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &B[i]);

    // Initialize L and U
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Doolittle Method
    for(i = 0; i < n; i++)
    {
        // Upper triangular
        for(j = i; j < n; j++)
        {
            sum = 0;
            for(k = 0; k < i; k++)
                sum += (L[i][k] * U[k][j]);

            U[i][j] = A[i][j] - sum;
        }

        // Lower triangular
        for(j = i; j < n; j++)
        {
            if(i == j)
                L[i][i] = 1;
            else
            {
                sum = 0;
                for(k = 0; k < i; k++)
                    sum += (L[j][k] * U[k][i]);

                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }

    // Forward substitution LY = B
    for(i = 0; i < n; i++)
    {
        sum = 0;
        for(j = 0; j < i; j++)
            sum += L[i][j] * Y[j];

        Y[i] = B[i] - sum;
    }

    // Backward substitution UX = Y
    for(i = n-1; i >= 0; i--)
    {
        sum = 0;
        for(j = i+1; j < n; j++)
            sum += U[i][j] * X[j];

        X[i] = (Y[i] - sum) / U[i][i];
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++)
        printf("x%d = %.3f\n", i+1, X[i]);

    return 0;
}