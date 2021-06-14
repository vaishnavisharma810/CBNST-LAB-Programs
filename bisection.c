#include <stdio.h>
#include <math.h>
float func(float a)
{
    return 4 * a * a * a - 9 * a;
}
int main()
{
    float a, b;
    do
    {
        printf("Enter the two inital guesses\n");
        scanf("%f%f", &a, &b);
        printf("%f%f", func(a), func(b));
        if (func(a) * func(b) < 0)
        {
            printf("root lies between a and b %d %d \n", a, b);
            break;
        }
        else if (func(a) * func(b) == 0)
        {
            if (func(a) == 0)
            {
                printf("root is %d", a);
                return 0;
            }
            else
            {
                printf("root is %d", b);
                return 0;
            }
        }
        else
        {
            printf("\nyour initial guesses were wrong .... try again!!\n");
        }
    } while (1);
    float c = (a + b) / 2.0;
    int iter;
    float e;
    printf("enter the number of iterrations\n");
    scanf("%d", &iter);
    printf("enter the tolerance\n");
    scanf("%d", &e);
    int i;
    for (i = 0; i < iter; i++)
    {
        float temp = c;
        if (func(c) * func(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
        c = (a + b) / 2.0;
        if (fabs(c - temp) < e)
        {
            printf("root of the equation is %d", c);
            return 0;
        }
    }
}
