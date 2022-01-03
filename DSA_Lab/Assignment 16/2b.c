#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int value;
	
	struct node *next;
};
struct node *front=NULL,*rear=NULL;

struct node *temp,*newnode;
void ENQUEUE(int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		rear=newnode;
		newnode->value=val;
		
		newnode->next=NULL;
		rear=newnode;
		front=rear;
	}
	else
	{
		struct node *rear=front;
		while(rear->next!=NULL)
		{
			rear=rear->next;
		}
		newnode->value=val;
		newnode->next=NULL;
		
		rear->next=newnode;
		rear=newnode;
	}
}
void display()
{
	if(front==NULL)
	printf("\nList is empty!!!");
	else
	{
		printf("\n");
		printf("\n");
		struct node *rear=front;
		while(rear->next!=NULL)
		{
			printf("%d ",rear->value);
			rear=rear->next;
		}
		printf("%d ",rear->value);
	}
}





void DEQUEUE()
{
	if(front==NULL)
	printf("\nList is empty!!!");
	else
	{
		struct node *temp=front;
		front=front->next;
		
		free(temp);
	}
}

int main()
{
	int choice,v,l=1;
	while(l)
	{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter value to store:");
				scanf("%d",&v);
				ENQUEUE(v);
				break;
			case 2:
				DEQUEUE();
				break;
			case 3:
				display();
				break;
			case 4:
				l=0;
				break;
			default:
				printf("\nInvalid Input!!");
				break;	
		}
	}
}
