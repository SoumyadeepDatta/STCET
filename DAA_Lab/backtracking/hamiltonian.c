#include<stdio.h>
#define M 20
int mat[M][M];
int x[M];
int path=1;
void nextValue(int k,int n)
{

    while(1)
    {
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0)
        {
            return;
        }
        if(mat[x[k-1]][x[k]] != 0)
        {
            int j;
            for(j=0;j<=k-1;j++)
            {
                if(x[j]==x[k])
                {
                    break;
                }
            }
                if(j==k)
                {
                    if((k<n) || ((k==n-1) && (mat[x[k]][x[0]] != 0)))
                    {
                        return;
                    }
                }

        }
    }
}

void hamiltonian(int k, int n)
{
    int path=0;
    while(1)
    {
        nextValue(k,n);
        if(x[k]==0)
        {
            return;
        }
        if(k==n-1)
        {
            //printf("\n\nPath %d\n\n",path);
            for(int t=0;t<n;t++)
            {
                printf("V%d\t",x[t]+1);
            }
            printf("V%d\t\n",x[0]+1);
            path++;
        }
        else
        {
            hamiltonian(k+1,n);
        }
    }
}

int main()
{
    int n,i,j,c,h;

    printf("\nEnter n. of vertices :");
    scanf("%d",&n);
    int x[n];
for(int i=0;i<n;i++)
{
x[i]=0;
}
    printf("\nEnter 1(if edge exists) else 0:");
    // int mat[n+1][n+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
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
                    printf("\n%d to %d :",i+1,j+1);
                    scanf("%d",&mat[i][j]);
                }
            }
        }
    }
    x[0]=0;
    hamiltonian(1,n);
    return 0;
}
