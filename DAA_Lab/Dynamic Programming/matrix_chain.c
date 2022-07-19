// Soumyadeep Datta Roll 26

#include <limits.h>
#include <stdio.h>

void printOptimalParanthesis(int n,int i,int j,int array[n][n])
{
    // printf("\n");
    if (i == j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        printOptimalParanthesis(n,i,array[i][j],array);
        printOptimalParanthesis(n,(array[i][j])+1,j,array);
        printf(")");
    }
    
}
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
void MatrixChainOrder(int p[], int n)
{

	/* For simplicity of the program,
	one extra row and one
	extra column are allocated in m[][].
	0th row and 0th
	column of m[][] are not used */
	int m[n][n];
    int s[n][n];

	int i, j, k, L, q;

	/* m[i, j] = Minimum number of
	scalar multiplications
	needed to compute the matrix
	A[i]A[i+1]...A[j] =
	A[i..j] where dimension of A[i]
	is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix.
	for (i = 1; i < n; i++)
		{m[i][i] = 0;
         s[i][i] = 0;
        }

	// L is chain length.
	for (L = 2; L < n; L++) {
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					{m[i][j] = q;
                    s[i][j] = k;}
			}
		}
	}
    printf("\n*****************M*****************\n\n");
    int r,c;
    for(r=1;r<n;r++)
    {
        for(c=1;c<n;c++)
        {
            if(r>c)
            {
                printf("-\t");
            }
            else
            {
                printf("%d\t",m[r][c]);
            }
            
        }
        printf("\n");
    }
    printf("\n*****************S*****************\n\n");
    for(r=1;r<n;r++)
    {
        for(c=1;c<n;c++)
        {
            if(r>c)
            {
                printf("-\t");
            }
            else
            {
                printf("%d\t",s[r][c]);
            }
            
        }
        printf("\n");
    }
    printf("\n");
    printf("\n***************ANSWER***************\n\n");
	printOptimalParanthesis(n,1,n-1,s);
}

// Driver code
int main()
{
	int t,f;
    printf("No. of consecutive dimensions:");
    scanf("%d",&t);
    int arr[t];
    printf("\nEnter the dimensions:\n");
    for(f=0;f<t;f++)
    {
        scanf("%d",&arr[f]);
    }
    // int arr[] = { 4,5,3,2,7,2 };
	int size = sizeof(arr) / sizeof(arr[0]);

	// printf("Minimum number of multiplications is %d ",
		MatrixChainOrder(arr, size);

	getchar();
	return 0;
}
