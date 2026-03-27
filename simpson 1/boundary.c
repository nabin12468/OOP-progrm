#include <stdio.h>

// Function defining y'' = f(x,y,y')
float f(float y) {
    return -y;   // y'' = -y
}

int main() {
    float x0, y0, xn, yn, h;
    float guess1, guess2;   // 
    int n, i;

    // 
    printf("Enter x0, y0 (initial boundary): ");
    scanf("%f %f", &x0, &y0);

    printf("Enter xn, yn (final boundary): ");
    scanf("%f %f", &xn, &yn);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter first guess for y'(x0): ");
    scanf("%f", &guess1);

    printf("Enter second guess for y'(x0): ");
    scanf("%f", &guess2);

    n = (int)((xn - x0) / h); // number of steps

    // Solve IVP for first guess
    float x = x0, y = y0, z = guess1, y1;
    for(i=0; i<n; i++){
        y = y + h * z;
        z = z + h * f(y);
        x = x + h;
    }
    y1 = y;

    // Solve IVP for second guess
    x = x0; y = y0; z = guess2;
    float y2;
    for(i=0; i<n; i++){
        y = y + h * z;
        z = z + h * f(y);
        x = x + h;
    }
    y2 = y;

    // Interpolate correct slope
    float correct_slope = guess1 + (guess2 - guess1) * (yn - y1) / (y2 - y1);

    // Solve final solution with correct slope
    x = x0; y = y0; z = correct_slope;
    printf("\nSolution:\n");
    printf("x\t y\n");
    for(i=0; i<=n; i++){
        printf("%.2f\t %.4f\n", x, y);
        float y_next = y + h*z;
        float z_next = z + h*f(y);
        y = y_next;
        z = z_next;
        x = x + h;
    }

    return 0;
}