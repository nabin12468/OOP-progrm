#include <stdio.h>

int main()
{
    int n, i, j;
    float x[20], y[20], xp, yp = 0, p;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for(i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the value of x to interpolate: ");
    scanf("%f", &xp);

    for(i = 0; i < n; i++)
    {
        p = 1;
        for(j = 0; j < n; j++)
        {
            if(i != j)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }

    printf("\nInterpolated value at x = %.2f is %.4f\n", xp, yp);

    return 0;
}