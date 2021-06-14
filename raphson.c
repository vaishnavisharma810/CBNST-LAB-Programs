#include <stdio.h>
#include <math.h>
float func(float a)
{
    return a * a * a - 4 * a - 9;
}
float diff(float a)
{
    return 3 * a * a - 4;
}
int main()
{
    float a, b;
    printf("Enter the inital guess\n");
    scanf("%f", &a);
    int iter;
    float e;
    printf("enter the number of iterrations\n");
    scanf("%d", &iter);
    printf("enter the tolerance\n");
    scanf("%f", &e);
    int i;
    for (i = 0; i < iter; i++)
    {
        float d = a - (func(a) / diff(a));
        if (fabs(a - d) <= e)
        {
            printf("root of the equation is %f", d);
            return 0;
        }
        else
        {
            a = d;
        }
    }
}
