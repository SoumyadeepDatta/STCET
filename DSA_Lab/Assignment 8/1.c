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
		
		newnode->next=start;
		temp=newnode;
	}
	else
	{
		newnode->value=val;
		
		newnode->next=start;
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
		struct node *x=start;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->value=val;
		while(x->next!=start)
		{
			x=x->next;
		}
		newnode->next=start;
		
		x->next=newnode;
		
		start=newnode;
	}
}
void insertEnd(int val)
{
	if(start==NULL)
	printf("\nUnderflow. List is empty!!");
	else{
		struct node *x=start;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->value=val;
		while(x->next!=start)
		{
			x=x->next;
		}
		newnode->next=start;
		
		x->next=newnode;
		
	}
}
void deleteFront()
{
	if(start==NULL)
	{
		printf("\nUnderflow. List is empty!!");
		return;
	}
	if(start->next==start)
	{
		start=NULL;
		return;
	}
	struct node *x=start,*temp;
	temp=start;
	while(x->next!=start)
	{
		x=x->next;
	}
	start=start->next;
	x->next=start;
	free(temp);
		
	
}
void deleteEnd()
{
	if(start==NULL)
	{
		printf("\nUnderflow. List is empty!!");
		return;
	}
	if(start->next==start)
	{
		start=NULL;
		return;
	}
	struct node *x=start,*temp,*y;
	
	while(x->next!=start)
	{
		y=x;
		x=x->next;
	}
	temp=x;
	y->next=start;
	free(temp);
}
void insertAfter(int key, int val)
{
	if(start==NULL)
	{
		printf("\nUnderflow. List is empty!!");
		return;
	}
	if (start->value==key && start->next==start)
	{
		insertEnd(val);
		return;
	}
	struct node *x=start;
	while(x->value!=key)
	{
		if(x->next==start)
		{
			printf("\nKey not found");
			return;
		}
		x=x->next;
	}
	if(x->value==key && x->next==start)
	{
		insertEnd(val);
		return;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	newnode->next=x->next;
	x->next=newnode;
}
void insertBefore(int key,int val)
{
	if(start==NULL)
	{
		printf("\nUnderflow. List is empty!!");
		return;
	}
	if(start->value==key)
	{
		insertFront(val);
		return;
	}
	struct node *x=start,*temp;
	while(x->value!=key)
	{
		if(x->next==start && x->value!=key)
		{
			printf("\nKey not found");
			return;
		}
		temp=x;
		x=x->next;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	temp->next=newnode;
	newnode->next=x;
}
void deleteBefore(int key)
{
	if(start==NULL)
	{
		printf("\nUnderflow. List is empty!!");
		return;
	}
	if(start->value==key && start->next==start)
	{
		start=NULL;
		return;
	}
	if(start->value==key && start->next!=start)
	{
		deleteEnd();
		return;
	}
	if(start->next->value==key)
	{
		deleteFront();
		return;
	}
	struct node *t=start,*temp,*x;
    x=t->next->next;
    while(x->value!=key )
	{
		if(x==start)
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
void deleteAfter(int key)
{
	if(start==NULL)
	{
		printf("\nUnderflow. List is empty!!");
		return;
	}
	if(start->value==key && start->next==start)
	{
		start=NULL;
		return;
	}
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
		deleteFront();
		return ;
	}
	temp=x->next;
	x->next=temp->next;
	
	free(temp);
	
}
void del()
{
	if(start==NULL)
	{
		printf("\nList already empty");
		return;
	}
	struct node *x=start,*temp;
	x=x->next;
	while (x!=start)
	{
		temp=x;
		x=x->next;
		free(temp);
	}
	start=NULL;
}
int main()
{
	int z,c,v,i,k;
	do{
		printf("\n\n1.create\n2.display\n3.insert at front\n4.insert at end");
		printf("\n5.Delete 1st node\n6.Delete last node\n7.Delete after a specific node");
		printf("\n8.Delete entire list\n9.Insert after a key node\n10.Insert before a key node");
		printf("\n11.Delete before a key node\n0.stop");
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
			case 8:
				del();
				break;
			case 9:
				printf("\nEnter key and value:");
				scanf("%d%d",&k,&v);
				insertAfter(k,v);
				break;
			case 10:
				printf("\nEnter key and value:");
				scanf("%d%d",&k,&v);
				insertBefore(k,v);
				break;
			case 11:
				printf("Enter value of the key:");
				fflush(stdin);
				scanf("%d",&i);
				deleteBefore(i);
				break;
			default:
				printf("\nInvalid input");
				break;				
		}
	}while(z!=0);
}
