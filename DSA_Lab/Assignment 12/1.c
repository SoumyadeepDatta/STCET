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
		newnode->prev=start;
		newnode->next=start;
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
	printf("\nUnderflow. List is empty!!");
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
	printf("\nUnderflow. List is empty!!");
	else{
		struct node *x;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->value=val;
		x=start->prev;
		newnode->next=start;
		newnode->prev=x;
		x->next=newnode;
		start->prev=newnode;
		
	}
}
void deleteFront()
{
	if(start==NULL)
	printf("\nUnderflow. List is empty!!");
	else{
		struct node *x,*temp;
		temp=start;
		x=start->next;
		x->prev=start->prev;
		start->prev->next=x;
		free(temp);
		start=x;
	}
}
void deleteEnd()
{
	if(start==NULL)
	printf("\nUnderflow. List is empty!!");
	else{
		struct node *x,*temp;
		temp=start->prev;
		x=start->prev->prev;
		start->prev=x;
		x->next=start;
		free(temp);
	}
}
void deleteAfter(int key)
{
	if(start==NULL)
	printf("\nUnderflow. List is empty!!");
	else{
		struct node *x,*temp;
		x=start;
		while(x->value!=key)
		{
			if(x->value!=key && x->next==start)
			{
				printf("\nKey not found!!!");
				return;
			}
			else
			x=x->next;
		}
		if(x->next==start && x->value==key)
		{
			printf("\nUnderflow!!! Key is last node!!!");
			return ;
		}
		temp=x->next;
		x->next=temp->next;
		temp->next->prev=x;
		free(temp);
	}
}
int main()
{
	int z,c,v,i;
	do{
		printf("\n\n1.create\n2.display\n3.insert at front\n4.insert at end");
		printf("\n5.Delete 1st node\n6.Delete last node\n7.Delete after a specific node\n0.stop");
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
			case 5:
				deleteFront();
				break;
			case 6:
				deleteEnd();
				break;
			case 7:
				printf("Enter value of the key:");
				scanf("%d",&i);
				deleteAfter(i);
				break;
			default:
				printf("\nInvalid input");
				break;				
		}
	}while(z!=0);
}
