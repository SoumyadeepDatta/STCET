#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *prev;
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
		newnode->prev=NULL;
		newnode->next=NULL;
		temp=newnode;
	}
	else
	{
		newnode->value=val;
		newnode->prev=temp;
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
void insertFront(int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	newnode->prev=NULL;
	newnode->next=start;
	start->prev=newnode;
	start=newnode;
}
void insertEnd(int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	struct node *x=start;
	while(x->next!=NULL)
	{
		x=x->next;
	}
	newnode->value=val;
	newnode->next=NULL;
	newnode->prev=x;
	x->next=newnode;
}
int main()
{
	int z,v,k,c;
	do
	{
		printf("\n************************************");
		printf("\n1.Create a doubly linked list\n2.Display list\n3.Insert a node at front");
		printf("\n4.Insert a node at end\n0.STOP Program");
		
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
					printf("\nEnter value to insert:");
					fflush(stdin);
					scanf("%d",&v);
					insertFront(v);
					break;
				case 4:
					printf("\nEnter value to insert:");
					fflush(stdin);
					scanf("%d",&v);
					insertEnd(v);
					break;	
				
				case 0:
					break;
				default:
					printf("\nInvalid Input!!!");
					break;	
			}
	}while(z!=0);
	return 0;
}
