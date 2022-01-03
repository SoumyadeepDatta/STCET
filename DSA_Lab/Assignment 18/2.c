//O/P RESTRICTED DEQUEUE , SOUMYADEEP DATTA , ROLL - 65

#include<stdio.h>
#define M 50


int front=-1,rear=-1;
int a[M];

void enqueue(int val)
{
	int ch;
	printf("\n1.INSERT AT front\n2.INSERT AT rear");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			if(front==0 || front==-1) {
				printf("\nOverflow");
				return;
			}
			
			a[--front]=val;
			break;
		case 2:
			if(rear==M-1) {
				printf("\nOverflow");
				return;
			}
			if(front==-1) front=0;
			a[++rear]=val;
			break;
		default:
			printf("\nInvalid input");
	
}
}

void dequeue()
{
	
	if(front>rear  || front ==-1)
	{
		front=-1;rear=-1;
		printf("\nUnderflow");
		return;
	}
	front++;	
			
	
}

void display()
{
	if(front==-1 || front>rear)
	{
		front=-1;rear=-1;
		printf("\nEmpty!!");
		return;
	}
	int i;
	printf("\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",a[i]);
	}
	
}

int main()

{
	int c,v;
	while(1)
	{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPPLAY\n4.STOP");
		scanf("%d",&c);
		if(c==1)
		{
			printf("\nEnter value:");
			scanf("%d",&v);
			enqueue( v );
		}
		else if(c==2)
		{
			dequeue();
		}
		else if(c==3)
		{
			display();
		}
		else if(c==4)
		{
			break;
		}
		else
		{
			printf("\nInvalid Input");
		}
	}
	return 0;
}
