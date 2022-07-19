#include<stdio.h>
#include<math.h>
int n;

void strassen(int A[n][n], int B[n][n], int n)
{
	int i,j,k,l,s;
	l=log2(n);
	s=pow(2,l-1);
	int a11[s][s],a12[s][s],a21[s][s],a22[s][s];
	int b11[s][s],b12[s][s],b21[s][s],b22[s][s];
	int c11[s][s],c12[s][s],c21[s][s],c22[s][s];
	int P[s][s],Q[s][s],R[s][s],S[s][s],T[s][s],U[s][s],V[s][s];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i>=0 && i<s)
			{
				if(j>=0 && j<s)
				{
					a11[i][j]=A[i][j];
					b11[i][j]=B[i][j];
				}
				if(j>=s && j<n)
				{
					a12[i][j-(s)]=A[i][j];
					b12[i][j-(s)]=B[i][j];
				}
			}
			if(i>=s && i<n)
			{
				if(j>=0 && j<s)
				{
					a21[i-(s)][j]=A[i][j];
					b21[i-(s)][j]=B[i][j];
				}
				if(j>=s && j<n)
				{
					a22[i-(s)][j-(s)]=A[i][j];
					b22[i-(s)][j-(s)]=B[i][j];
				}
			}		
		}
	}

	int m1[s][s], m2[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			m1[i][j]=a11[i][j]+a22[i][j];
			m2[i][j]=b11[i][j]+b22[i][j];
		}
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			P[i][j]=0;
			for(k=0;k<s;k++)
				P[i][j] += m1[i][k]*m2[k][j];
		}
	}

	int m3[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			m3[i][j]=a21[i][j]+a22[i][j];
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			Q[i][j]=0;
			for(k=0;k<s;k++)
				Q[i][j] += m3[i][k]*b11[k][j];
		}
	}

	int m4[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			m4[i][j]=b12[i][j]-b22[i][j];
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			R[i][j]=0;
			for(k=0;k<s;k++)
				R[i][j] += a11[i][k]*m4[k][j];
		}
	}

	int m5[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			m5[i][j]=b21[i][j]-b11[i][j];
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			S[i][j]=0;
			for(k=0;k<s;k++)
				S[i][j] += a22[i][k]*m5[k][j];
		}
	}

	int m6[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			m6[i][j]=a11[i][j]+a12[i][j];
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			T[i][j]=0;
			for(k=0;k<s;k++)
				T[i][j] += m6[i][k]*b22[k][j];
		}
	}

	int m7[s][s], m8[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			m7[i][j]=a21[i][j]-a11[i][j];
			m8[i][j]=b11[i][j]+b12[i][j];
		}
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			U[i][j]=0;
			for(k=0;k<s;k++)
				U[i][j] += m7[i][k]*m8[k][j];
		}
	}	

	int m9[s][s], m10[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			m9[i][j]=a12[i][j]-a22[i][j];
			m10[i][j]=b21[i][j]+b22[i][j];
		}
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			V[i][j]=0;
			for(k=0;k<s;k++)
				V[i][j] += m9[i][k]*m10[k][j];
		}
	}

	int x1[s][s], x2[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			x1[i][j]=P[i][j]+S[i][j];
		}
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			x2[i][j]=x1[i][j]-T[i][j];
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			c11[i][j]=x2[i][j]+V[i][j];
	}

	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			c12[i][j]=R[i][j]+T[i][j];
	}

	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			c21[i][j]=Q[i][j]+S[i][j];
	}

	int x3[s][s], x4[s][s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			x3[i][j]=P[i][j]+R[i][j];
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			x4[i][j]=x3[i][j]-Q[i][j];
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
			c22[i][j]=x4[i][j]+U[i][j];
	}

	int final[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i>=0 && i<s)
			{
				if(j>=0 && j<s)
				{
					final[i][j]=c11[i][j];
				}
				if(j>=s && j<n)
				{
					final[i][j]=c12[i][j-s];
				}
			}
			if(i>=s && i<n)
			{
				if(j>=0 && j<s)
				{
					final[i][j]=c21[i-s][j];
				}
				if(j>=s && j<n)
				{
					final[i][j]=c22[i-s][j-s];
				}
			}		
		}
	}
	printf("\nThe Resultant Matrix is: \n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",final[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i,j;
	printf("Enter the order of matrix (n*n) \n(n is order of 2^k and k>=1): ");
	scanf("%d",&n);
	int A[n][n], B[n][n];
	printf("\nEnter Matrix A: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("\nEnter Matrix B: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	strassen(A,B,n);
	return 0;
}
