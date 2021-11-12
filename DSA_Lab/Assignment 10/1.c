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
void displayRev()
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
			x=x->next;
		}
		printf("\n****Reverse****\n");
		while(x->prev!=NULL)
		{
			printf("%d ",x->value);
			x=x->prev;
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
void insertAfter(int key,int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	struct node *x=start;
	while(x->value!=key)
	{
		if(x->next==NULL)
		{
			printf("\nKey not found!!!");
			break;
		}
		x=x->next;
	}
	newnode->value=val;
	newnode->next=x->next;
	x->next->prev=newnode;
	x->next=newnode;
	newnode->prev=x;
}
void insertBefore(int key,int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	struct node *x=start;
	while(x->value!=key)
	{
		if(x->next==NULL)
		{
			printf("\nKey not found!!!");
			break;
		}
		x=x->next;
	}
	newnode->value=val;
	x->prev->next=newnode;
	newnode->prev=x->prev;
	newnode->next=x;
	x->prev=newnode;
}
void deleteFront()
{
	if(start==NULL)
	printf("\nList is empty!!!");
	else
	{
		struct node *temp=start;
		start=start->next;
		start->prev=NULL;
		free(temp);
	}
}
void deleteEnd()
{
	if(start==NULL)
	printf("\nList is empty!!!");
	else
	{
		struct node *x=start,*temp;
		while(x->next!=NULL)
		{
			x=x->next;
		}
		temp=x;
		x=x->prev;
		x->next=NULL;
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
				break;
			}
			else
			x=x->next;
		}
		if(x->next==NULL && x->value==key)
		printf("\nUnderflow!!! Key is last node!!!");
		else
		{
			temp=x->next;
			x->next=temp->next;
			temp->next->prev=x;
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
		struct node *x=start;
		while(x->value!=key)
		{
			if(x->value!=key && x->next==NULL)
			{
				printf("\nKey not found!!!");
				break;
			}
			else
			x=x->next;
		}
		if(x->prev==NULL && x->value==key)
		printf("\nUnderflow!!! Key is first node!!!");
		else
		{
			temp=x->prev;
			x->prev=temp->prev;
			temp->prev->next=x;
			free(temp);
		}
	}
}
int main()
{
	int z,v,k,c;
	do
	{
		printf("\n************************************");
		printf("\n1.Create a doubly linked list\n2.Display list\n3.Display list in Reverse\n4.Insert a node at front");
		printf("\n5.Insert a node at end\n6.Insert after specific node\n7.Insert before specific node");
		printf("\n8.Delete first node\n9.Delete last node\n10.Delete after specific node");
		printf("\n11.Delete before specific node\n0.STOP Program");
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
					displayRev();
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
				case 0:
					break;
				default:
					printf("\nInvalid Input!!!");
					break;	
			}
	}while(z!=0);
	return 0;
}
