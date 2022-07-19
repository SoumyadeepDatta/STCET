#include<stdio.h>
struct job
{
    int index;
    int deadline;
    int profit;
};
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int jobSeq(int n)
{
    struct job array[n];
    int i=0,j;
    struct job temp;
    while(i<n)
    {
        array[i].index=i+1;
        printf("\nFor job %d",i+1);
        printf("\nDeadline:");
        scanf("%d",&array[i].deadline);
        printf("Profit:");
        scanf("%d",&array[i].profit);
        i++;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(array[j].profit<array[j+1].profit)
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    printf("\n********************After Sorting*******************************************************\n");
    printf("\nJob\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i].index);
    }
    printf("\n\nDeadline\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i].deadline);
    }
    printf("\n\nProfit\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i].profit);
    }
    int max=0;
    for(i=0;i<n;i++)
    {
        if (array[i].deadline>=max)
        {
            max=array[i].deadline;
        }   
    }
    int slots[max];
    int solution[max];
    for(i=0;i<max;i++)
    {
        slots[i]=0;
        solution[i]=0;
    }
    int sol_ind=0;
    int p=0,k;
    int flag,put,printed,space;
    printf("\n\n");
    printf("***********************Table************************************************************");
    printf("\n\n");
    printf("Soln-set\tSlot\t\tJob\tDeadline\tAction\t\t\tProfit");
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        flag=0;
        printed=0;
        space=0;
        printf("{");
        for(k=0;k<max;k++)
        {
            if(printed==0 && solution[k]!=0)
            {
                printf("%d",solution[k]);
                printed=1;
                space++;
            }
            else if(printed==1 && solution[k]!=0)
            {
                printf(",%d",solution[k]);
                space++;
            }
        }
        printf("}");
        if(space>=4)
        {
            printf("\t");
        }
        else
        {
            printf("\t\t");
        }
        for(j=0;j<max;j++)
        {
            printf("[%d]",slots[j]);
        }
        printf("\t");
        printf("%d",array[i].index);
        printf("\t");
        printf("%d",array[i].deadline);
        printf("\t\t");
        for(k=0;k<(array[i].deadline);k++)
        {
            if(slots[k]==0)
            {
                flag=1;
                put=k;
                break;
            }
        }
        if(flag==1)
        {
            if(slots[array[i].deadline-1]==0)
            {
                printf("Assign to slot %d",array[i].deadline);
            }
            else 
            {
                printf("Assign to slot %d",k+1);
            }
            // slots[array[i].deadline-1]=1;
            // solution[sol_ind]=array[i].index;
            // sol_ind++;
        }
        else
        {
            printf("Reject\t\t");
        }  
        printf("\t");
        if(flag==1)
        {
            printf("%d+%d=%d",p,array[i].profit,(p+array[i].profit));
            p=p+array[i].profit;
            if(slots[array[i].deadline-1]==0)
            {
                slots[array[i].deadline-1]=1;
                solution[sol_ind]=array[i].index;
                sol_ind++;
            }
            else
            {
                slots[k]=1;
                solution[sol_ind]=array[i].index;
                sol_ind++; 
            }
            // slots[k]=1;
            // solution[sol_ind]=array[i].index;
            // sol_ind++;  
            //slots[array[i].deadline-1]==0
        }
        else
        {
            printf("%d",p);
        }
        printf("\n\n");
    }
    printf("\n\n");
    printf("****************************************************************************************");
    printf("\n\n");
    printf("Soln-set = ");
    printed=0;
    printf("{");
        for(k=0;k<max;k++)
        {
            if(printed==0 && solution[k]!=0)
            {
                printf("%d",solution[k]);
                printed=1;
            }
            else if(printed==1 && solution[k]!=0)
            {
                printf(",%d",solution[k]);
            }
        }
    printf("}");
    for(i=0;i<max-1;i++)
    {
        for(j=0;j<max-i-1;j++)
        {
            if(solution[j]>solution[j+1])
            {
                swap(&solution[j],&solution[j+1]);
            }
        }
    }
    printf("\n\n");
    printf("Sorted Soln-set = ");
    printed=0;
    printf("{");
        for(k=0;k<max;k++)
        {
            if(printed==0 && solution[k]!=0)
            {
                printf("%d",solution[k]);
                printed=1;
            }
            else if(printed==1 && solution[k]!=0)
            {
                printf(",%d",solution[k]);
            }
        }
    printf("}");
    printf("\n\n");
    printf("Total Profit :\t%d",p);
    printf("\n\n");
    printf("****************************************************************************************");
    printf("\n\n");
    // printf("\n%d",max);
    // printf("\n\n");
    // printf("Soln-Set\tAssigned-Slot\tConsidered\tDeadline\tAction\t\tProfit");
    // printf("\n   2\t\t      2\t\t    2 \t\t    2\t\t   2\t\t  2");
}
int main()
{
    int n;
    printf("\n\n");
    printf("***********************Job Sequencing with Deadline*************************************");
    printf("\n");
    printf("\nEnter no. of jobs:");
    scanf("%d",&n);
    jobSeq(n);
}
