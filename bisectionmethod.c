#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x*x - x - 2;   // Example function
}

int main()
{
    float a, b, xm;
    int i;
     printf("Given Equation is : x^3-x-2=0 ");
    printf("\nEnter value of a and b (Initial guess): ");
    scanf("%f %f", &a, &b);

    if (f(a) * f(b) >= 0)
    {
        printf("Incorrect initial guesses.\n");
        return 0;
    }

    printf("\nIteration\t a\t b\t xm\n");

    for(i = 1; i <= 10; i++)
    {
        xm = (a + b) / 2;

        printf("%d\t\t %.4f\t %.4f\t %.4f\n", i, a, b, xm);

        if (f(xm) == 0.0)
            break;

        else if (f(a) * f(xm) < 0)
            b = xm;
        else
            a = xm;
    }

    printf("\nApproximate root = %.4f\n", xm);

    return 0;
}