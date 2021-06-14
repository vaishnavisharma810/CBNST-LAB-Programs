#include<stdio.h>
#include<math.h>
float f(float x)
{
    return cos(x) - x*exp(x);
}
void regula(float *x, float x0, float x1, float fx0, float fx1, int *itr)
{
    *x = x0 - ((x1-x0)/(fx1-fx0))*fx0;
    ++(*itr);
    printf("Iteration number %3d x = %7.5f\n",*itr,*x);
}
int main()
{
    int itr=0,maxitr;
    float x0,x1,x2,x3,aerr;
    printf("Enter the values for x0,x1 allowed error,maxm itern\n");
    scanf("%f%f%f%d",&x0,&x1,&aerr,&maxitr);
    regula(&x2,x0,x1,f(x0),f(x1),&itr);
    do
    {
        if(f(x0) * f(x2) < 0)
            x1 = x2;
        else
            x0 = x2;
        regula(&x3,x0,x1,f(x0),f(x1),&itr);
        if(fabs(x3 - x2) < aerr)
        {
            printf("After %d iterations roots = %6.4f\n",itr,x3);
            return 0;
        }
        x2 = x3;
    }while(itr < maxitr);
    printf("Solution does not converge iterations not sufficient\n");
    return 1;
}
