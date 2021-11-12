#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int value;
	
	struct node *next;
};
struct node *start=NULL;
struct node *temp,*newnode;
void insert(int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		start=newnode;
		newnode->value=val;
		
		newnode->next=NULL;
		temp=newnode;
	}
	else
	{
		newnode->value=val;
		
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
}
void display()
{
	if(start==NULL)
	printf("\nList is empty!!!");
	else
	{
		printf("\n");
		printf("\n");
		struct node *x=start;
		while(x->next!=NULL)
		{
			printf("%d ",x->value);
			x=x->next;
		}
		printf("%d ",x->value);
	}
}
void count()
{
    int cnt=0;
    if (start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    struct node *x=start;
	while(x->next!=NULL)
	{
		cnt++;
		x=x->next;
	}
	cnt++;
    fflush(stdin);
    printf("\nTotal nodes: %d",cnt);
}

void insertFront(int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	
	newnode->next=start;
	
	start=newnode;
}
void insertEnd(int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		start=newnode;
		newnode->value=val;
		
		newnode->next=NULL;
		temp=newnode;
		return;
	}
	struct node *x=start;
	while(x->next!=NULL)
	{
		x=x->next;
	}
	newnode->value=val;
	newnode->next=NULL;
	
	x->next=newnode;
}

void insertAfterN(int num, int val)
{
    int i;
    struct node *x=start;
    if(start==NULL)
    {
        printf("\nList empty!!");
            return;
    }
    for (i=1;i<num;i++)
    {
        if(x==NULL)
        {
            printf("\nOut of range");
            return;
        }
        
		x=x->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->value=val;
    newnode->next=x->next;
	
	x->next=newnode;
}



int main()
{
	int z,v,k,c;
	while(1)
	{
		printf("\n************************************");
		printf("\n1.Create a singly linked list\n2.Display list\n3.Count total nodes\n4.Insert a node at front");
		printf("\n5.Insert a node at end\n6.Insert after a specified number of node");
		printf("\n0.STOP Program");
		printf("\n************************************");
		scanf("%d",&z);
		switch(z){
				case 1:
					do{
						printf("\nEnter value:");
						scanf("%d",&v);
						insert(v);
						printf("\nPress 0 to stop. Press other integer to continue.");
						scanf("%d",&c);
					}while(c!=0);
					break;
				case 2:
					display();
					break;
				case 3:
					count();
					break;
				case 4:
					printf("\nEnter value to insert:");
					fflush(stdin);
					scanf("%d",&v);
					insertFront(v);
					break;
				case 5:
					printf("\nEnter value to insert:");
					fflush(stdin);
					scanf("%d",&v);
					insertEnd(v);
					break;	
				case 6:
					printf("\nEnter specified no. of nodes & value to insert:");
					fflush(stdin);
					scanf("%d%d",&k,&v);
					insertAfterN(k,v);
					break;	
				
				case 0:
					
                    break;
				default:
					printf("\nInvalid Input!!!");
					
			}
	}
	return 0;
}
