#include <stdio.h>
#include <math.h>

int main()
{
    // a^2 + b + c = 0
    double a, b, c, discriminant, root1, root2;
    printf("ax^2 + bx + c = 0\n");
    printf("Input value for a: ");
    scanf("%lf", &a);
    printf("Input value for b: ");
    scanf("%lf", &b);
    printf("Input value for c: ");
    scanf("%lf", &c);
    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different.\n");
        printf("Root 1: %lf\n", root1);
        printf("Root 2: %lf\n", root2);
    }
    else if (discriminant == 0)
    {
        root1 = -b / (2 * a);
        printf("Roots are real and same.\n");
        printf("Root 1: %lf\n", root1);
    }
    else
    {
        printf("Roots are complex and different.\n");
        printf("Root 1: %lf + %lfi\n", -b / (2 * a), sqrt(-discriminant) / (2 * a));
        printf("Root 2: %lf - %lfi\n", -b / (2 * a), sqrt(-discriminant) / (2 * a));
    }

    return 0;
}