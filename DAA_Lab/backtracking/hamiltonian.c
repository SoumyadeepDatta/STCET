#include<stdio.h>
#define M 20
int mat[M][M];
int x[M];
int path=1;
void nextValue(int k,int no)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(no+1);
        if(x[k]==0)
        {
            return;
        }
        if(mat[x[k-1]][x[k]] != 0)
        {
            for(j=1;j<=k-1;j++)
            {
                if(x[j]==x[k])
                {
                    break;
                }
            }
                if(j==k)
                {
                    if((k<no) || ((k==no) && (mat[x[no]][x[1]] != 0)))
                    {
                        return;
                    }
                }
            
        }
    }
}

void hamiltonian(int k, int no)
{
    int t;
    while(1)
    {
        nextValue(k,no);
        if(x[k]==0)
        {
            return;
        }
        if(k==no)
        {
            printf("\n\nPath %d\n\n",path);
            for(t=1;t<=no;t++)
            {
                printf("V%d\t",x[t]);
            }
            path++;
        }
        else
        {
            hamiltonian(k+1,no);
        }
    }
}

int main()
{
    int n,i,j,c,h;
    
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
    hamiltonian(1,n);
    return 0;
}
