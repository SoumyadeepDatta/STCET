#include<stdio.h>//Roll 65
#define MAX 5
int top=-1;
void push(int val, int a[])
{
	
	if(top==MAX-1)
	{
		printf("\nOverflow");
	}
	else{
	
	++top;
	a[top]=val;
	}
}
int pop(int a[])
{
	if(top==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		--top;
		return a[top+1];
	}
}
void display(int a[])
{
	int i;
	printf("\n");
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else{
	
	for(i=0;i<=top;i++)
	{
		printf("%d\t",a[i]);
	}
	}
}
int main()
{
	int s[MAX],c,v;
	do{
		printf("\n1.push\n2.pop\n3.display\n0.stop");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nEnter value to push");
				scanf("%d",&v);
				push(v,s);
				break;
			case 2:
				printf("\nPopped value is %d",pop(s));
				break;
			case 3:
				display(s);
				break;
			case 0:
				break;
			default:
				printf("\nInvalid Input!!!");
				break;	
			
		}
	}while(c!=0);
	return 0;
}
