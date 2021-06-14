#include<stdio.h>
#define F(x,y) (x-y)/(x+y)
int main()
{
    int i,n;
    float x0,y0,x,xn,y,h,k,k1,k2,k3,k4;
    printf("Enter the values: x0,y0,h,xn:\n");
    scanf("%f%f%f%f",&x0,&y0,&h,&xn);
    n=(xn-x0)/h;
    x=x0;
    y=y0;
    for(i=1; i<=n; i++)
    {
        k1=h*F(x,y);
        k2=h*F(x+h/2.0,y+k1/2.0);
        k3=h*F(x+h/2.0,y+k2/2.0);
        k4=h*F(x+h,y+k3);
        k=(k1+2.0*(k2+k3)+k4)/6.0;
        x+=h;
        y+=k;

    }
    printf("at x=%f, y=%f\n",x,y);
    return 0;
}

