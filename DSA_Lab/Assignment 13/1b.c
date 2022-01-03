#include<stdio.h>//Roll 65
#include<malloc.h>
#include<stdlib.h>
struct node{
	int value;
	
	struct node *next;
};
struct node *start=NULL;
struct node *temp,*newnode;
void push(int val)
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
	printf("\nStack is empty!!!");
	else
	{
		printf("\n");
		printf("\n");
		struct node *x=start;
		while(x->next!=NULL)
		{
			printf("%d\t",x->value);
			x=x->next;
		}
		printf("%d\t",x->value);
	}
}

void pop()
{
	if(start==NULL)
	printf("\nUnderflow!!!");
	else
	{
		if(start->next==NULL)
		{
			temp=start;
			start=NULL;
			free(temp);
			return;
		}
		else
		{
		struct node *x=start,*temp,*a;
		while(x->next!=NULL)
		{
			a=x;
			x=x->next;
		}
		temp=x;
		x=a;
		x->next=NULL;
		free(temp);
		}
	}
}
int main()
{
	int z,v;
	do
	{
		
		printf("\n1.push\n2.pop\n3.display\n0.stop");
		
		scanf("%d",&z);
		switch(z){
				case 1:
					
					printf("\nEnter value:");
					scanf("%d",&v);
					push(v);
					
					
					
					break;
				case 3:
					display();
					break;
				case 2:
					pop();
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
