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
		newnode->next=start;
		temp->next=newnode;
		start->prev=newnode;
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
		while(x->next!=start)
		{
			printf("%d ",x->value);
			x=x->next;
		}
		printf("%d ",x->value);
	}
}
void insertFront(int val)
{
	if(start==NULL)
	printf("\nUnderflow");
	else{
		struct node *x;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->value=val;
		x=start->prev;
		newnode->next=start;
		newnode->prev=x;
		x->next=newnode;
		start->prev=newnode;
		start=newnode;
	}
}
void insertEnd(int val)
{
	if(start==NULL)
	printf("\nUnderflow");
	else{
		struct node *x;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->value=val;
		x=start->prev;
		newnode->next=start;
		newnode->prev=x;
		x->next=newnode;
		start->prev=newnode;
		//start=newnode;
	}
}
int main()
{
	int z,c,v;
	do{
		printf("\n1.create\n2.display\n3.insert at front\n4.insert at end\n0.stop");
		scanf("%d",&z);
		switch(z)
		{
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
			case 0:
				break;
			case 4:
				printf("\nEnter value to insert:");
				fflush(stdin);
				scanf("%d",&v);
				insertEnd(v);
				break;
			default:
				printf("\nInvalid input");
				break;				
		}
	}while(z!=0);
}
