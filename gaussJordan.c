#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    float ar[n][n+1];
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            scanf("%f",&ar[i][j]);
        }
    }
    int l,m;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                float count;
                if(ar[i][i]!=0)
                    count=ar[j][i]/ar[i][i];
                else
                {
                    for(l=0; l<n+1; l++)
                    {
                        int temp=ar[i][l];
                        ar[i][l]=ar[n-1][l];
                        ar[n-1][l]=temp;
                    }
                    count=ar[j][i]/ar[i][i];
                }
                for(k=0; k<n+1; k++)
                {
                    ar[j][k]=ar[j][k]-count*ar[i][k];
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            printf("%f ",ar[i][j]);
        }
        printf("\n");
    }
    float x[3],sum=0.0;
    for(i=n-1; i>=0; i--)
    {
        x[i]=ar[i][n]/ar[i][i];
        printf("%f\n",x[i]);
    }
}

