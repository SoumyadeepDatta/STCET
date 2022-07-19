//SOUMYADEEP DATTA ROLL 26
#include<stdio.h>

struct element{
    int index;
    int weight;
    float profit;
    float knapsack;
};
void bubbleSort(struct element array[50], int n);
void F_knapsack(int n,int c)
{
    struct element array[n];
    int i=0;
    
    while (i<n)
    {
        array[i].index=i;
        array[i].knapsack=0;
        printf("\nEnter weight,profit:");
        scanf("%d%f",&array[i].weight,&array[i].profit);
        i++;
    }
    int j;
    struct element t;
    printf("\nBy ratio\n");
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
           if ((float)((array[j].profit)/array[j].weight) < (float)((array[j+1].profit)/array[j+1].weight))
           {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
           }
    int c_left=c;
    float total_profit=0;
    for(i=0;(i<n)&&(c_left>0);i++)
    {
        if(array[i].weight<c_left)
        {
            array[i].knapsack=1;
            // printf("\n%f",array[i].knapsack);//
            c_left=c_left-array[i].weight;
            total_profit=total_profit+array[i].profit;
        }
        else
        {
            array[i].knapsack=(float)(1.0*c_left/(1.0*array[i].weight));
            // printf("\n%f",array[i].knapsack);//
            total_profit=total_profit+(float)((array[i].profit)*(array[i].knapsack));
            c_left=0;
        }
        
    }
    
    bubbleSort(array,n);
    printf("\nTotal profit : %f\n",total_profit);
    printf("\nKnapsack vector :\n");
    for(i=0;i<n;i++)
    {
        printf("%f\t",array[i].knapsack);
    }
    //###################################################################################################
    printf("\nBy profit\n");
    bubbleSort(array,n);
    
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
           if ((float)((array[j].profit)) < (float)((array[j+1].profit)))
           {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
           }
    c_left=c;
    total_profit=0;
    for(i=0;(i<n)&&(c_left>0);i++)
    {
        if(array[i].weight<c_left)
        {
            array[i].knapsack=1;
            // printf("\n%f",array[i].knapsack);//
            c_left=c_left-array[i].weight;
            total_profit=total_profit+array[i].profit;
        }
        else
        {
            array[i].knapsack=(float)(1.0*c_left/(1.0*array[i].weight));
            // printf("\n%f",array[i].knapsack);//
            total_profit=total_profit+(float)((array[i].profit)*(array[i].knapsack));
            c_left=0;
        }
        
    }
    
    bubbleSort(array,n);
    printf("\nTotal profit : %f\n",total_profit);
    printf("\nKnapsack vector :\n");
    for(i=0;i<n;i++)
    {
        printf("%f\t",array[i].knapsack);
    }
    //###################################################################################################
    printf("\nBy weight\n");
    bubbleSort(array,n);
    
    
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
           if (array[j].weight > array[j+1].weight)
           {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
           }
    c_left=c;
    total_profit=0;
    for(i=0;(i<n)&&(c_left>0);i++)
    {
        if(array[i].weight<c_left)
        {
            array[i].knapsack=1;
            // printf("\n%f",array[i].knapsack);//
            c_left=c_left-array[i].weight;
            total_profit=total_profit+array[i].profit;
        }
        else
        {
            array[i].knapsack=(float)(1.0*c_left/(1.0*array[i].weight));
            // printf("\n%f",array[i].knapsack);//
            total_profit=total_profit+(float)((array[i].profit)*(array[i].knapsack));
            c_left=0;
        }
        
    }
    
    bubbleSort(array,n);
    printf("\nTotal profit : %f\n",total_profit);
    printf("\nKnapsack vector :\n");
    for(i=0;i<n;i++)
    {
        printf("%f\t",array[i].knapsack);
    }
}

void bubbleSort(struct element array[50], int n)
{
   int i, j;
   struct element temp;
   for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
           if (array[j].index > array[j+1].index)
           {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
           }
            
}
int main()
{
    int n,c;
    printf("Enter range,capacity:");
    scanf("%d%d",&n,&c);
    F_knapsack(n,c);
}
