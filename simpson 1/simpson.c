#include <stdio.h>
#include <math.h>

// Function to integrate
float f(float x)
{
    return x * x;   // Example function f(x) = x^2
}

int main()
{
    int n, i;
    float a, b, h, sum = 0, x;

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    printf("Enter number of intervals (even number): ");
    scanf("%d", &n);

    // ✅ Check if n is even
    if (n % 2 != 0)
    {
        printf("Error: Number of intervals must be even.\n");
        return 1;
    }

    h = (b - a) / n;

    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
    {
        x = a + i * h;

        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    sum = sum * h / 3;

    printf("\nIntegral value = %.4f\n", sum);

    return 0;
}