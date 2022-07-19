#include<stdio.h>
#define M 20
int mat[M][M];
int x[M];
int sol=1;
void nextValue(int k,int m,int no)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
        {
            return;
        }
        for(j=1;j<=no;j++)
        {
            if((mat[k][j] != 0) && (x[k]==x[j]))
            {
                break;
            }
        }
        if(j==no+1)
        {
            return;
        }
    }
}

void mColoring(int k,int cl,int no)
{
    int t;
    while(1)
    {
        nextValue(k,cl,no);
        if(x[k]==0)
        {
            return;
        }
        if(k==no)
        {
            printf("\n\nSolution %d :\n\n",sol);
            for(t=1;t<=no;t++)
            {
                printf("V%d\t",t);
            }
            printf("\n");
            for(t=1;t<=no;t++)
            {
                printf("%d\t",x[t]);
            }
            sol++;
        }
        else
        {
            mColoring(k+1,cl,no);
        }
    }
}


int main()
{
    int n,i,j,c,h;
    printf("Enter no. of colours :");
    scanf("%d",&c);
    printf("\nYour colours are :\n");
    for(h=1;h<=c;h++)
    {
        printf("%d\t",h);
    }
    printf("\n");
    printf("\nEnter no. of vertices :");
    scanf("%d",&n);
    printf("\nEnter 1(if edge exists) else 0:");
    // int mat[n+1][n+1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                mat[i][j]=0;
            }
            else
            {
                if(i>j)
                {
                    mat[i][j]=mat[j][i];
                }
                else
                {
                    printf("\n%d to %d :",i,j);
                    scanf("%d",&mat[i][j]);
                }
            }
        }
    }
    mColoring(1,c,n);
    return 0;
}
