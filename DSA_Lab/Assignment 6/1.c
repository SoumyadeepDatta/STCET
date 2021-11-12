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
void insertAfter(int key,int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	struct node *x=start;
	while(x->value!=key)
	{
		if(x->next==NULL)
		{
			printf("\nKey not found!!!");
			return;
		}
		x=x->next;
	}
	newnode->value=val;
	newnode->next=x->next;
	
	x->next=newnode;
	
}
void insertBefore(int key,int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	struct node *x=start,*y;
	while(x->value!=key)
	{
		if(x->next==NULL)
		{
			printf("\nKey not found!!!");
			return;
		}
		y=x;
        x=x->next;
	}
	newnode->value=val;
	y->next=newnode;
	
	newnode->next=x;
	
}
void deleteFront()
{
	if(start==NULL)
	printf("\nList is empty!!!");
	else
	{
		struct node *temp=start;
		start=start->next;
		
		free(temp);
	}
}
void deleteEnd()
{
	if(start==NULL)
	printf("\nList is empty!!!");
	else
	{
		struct node *x=start,*temp,*y;
		while(x->next!=NULL)
		{
			y=x;
            x=x->next;
		}
		temp=x;
		
		y->next=NULL;
		free(temp);
	}
}
void deleteAfter(int key)
{
	if(start==NULL)
	{
		printf("\nList is empty!!!");
	}
	else
	{
		struct node *x=start;
		while(x->value!=key)
		{
			if(x->value!=key && x->next==NULL)
			{
				printf("\nKey not found!!!");
				return;
			}
			else
			x=x->next;
		}
		if(x->next==NULL && x->value==key)
		{
			printf("\nUnderflow!!! Key is last node!!!");
			return;
		}
		else
		{
			temp=x->next;
			x->next=temp->next;
			
			free(temp);
		}
	}
}
void deleteBefore(int key)
{
	if(start==NULL)
	{
		printf("\nList is empty!!!");
	}
	else
	{
		struct node *t=start,*temp,*x;
        x=t->next->next;
		
		if(start->value==key)
		{
			printf("\nUnderflow!!! Key is first node!!!");
			return;
		}
		if(start->next->value==key)
        {
            temp=start;
            start=start->next;
            free(temp);
            return;
        }
        while(x->value!=key )
		{
			if(x==NULL)
			{
				printf("\nKey not found!!!");
				return;
			}
			else
			
            t=t->next;
			x=t->next->next;
		}
        temp=t->next;
        t->next=x;
        free(temp);
	}
}
void search(int key)
{
	int count=1;
	if (start==NULL)
	{
		printf("\nList is empty");
		return;
	}
	struct node *x=start;
	while(x->value!=key)
	{
		if(x==NULL)
		{
			printf("\nKey not found");
			return;
		}
		x=x->next;
		count++;
	}
	printf("\nItem found at %d position",count);
}
int main()
{
	int z,v,k,c;
	while(1)
	{
		printf("\n************************************");
		printf("\n1.Create a singly linked list\n2.Display list\n3.Count total nodes\n4.Insert a node at front");
		printf("\n5.Insert a node at end\n6.Insert after specific node\n7.Insert before specific node");
		printf("\n8.Delete first node\n9.Delete last node\n10.Delete after specific node");
		printf("\n11.Delete before specific node\n12.Search for key element\n0.STOP Program");
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
					printf("\nEnter key value & value to insert:");
					fflush(stdin);
					scanf("%d%d",&k,&v);
					insertAfter(k,v);
					break;	
				case 7:
					printf("\nEnter key value & value to insert:");
					fflush(stdin);
					scanf("%d%d",&k,&v);
					insertBefore(k,v);
					break;	
				case 8:
					deleteFront();
					break;
				case 9:
					deleteEnd();
					break;	
				case 10:
					printf("\nEnter key value:");
					fflush(stdin);
					scanf("%d",&k);
					deleteAfter(k);
					break;
				case 11:
					printf("\nEnter key value:");
					fflush(stdin);
					scanf("%d",&k);
					deleteBefore(k);
					break;
				case 12:
					printf("\nEnter key value:");
					fflush(stdin);
					scanf("%d",&k);
					search(k);
					break;
				case 0:
					
                    break;
				default:
					printf("\nInvalid Input!!!");
					
			}
	}
	return 0;
}
