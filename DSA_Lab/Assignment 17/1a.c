//SOUMYADEEP DATTA ROLL 65
//CQ USING ARRAY
#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;


int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}


int isEmpty() {
  if (front == -1) return 1;
  return 0;
}


void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}


int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}


void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    
  }
}

int main() {
  int ch,value;
  while(1)
  {
  	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.STOP");
  	scanf("%d",&ch);
  	if(ch==1)
  	{
  		printf("\nEnter element:");
  		scanf("%d",&value);
  		enQueue(value);
	  }
	else if(ch==2)
	{
	 	deQueue();
	  }
	else if(ch==3)
	{
	 	display();
	  }
	else if(ch==4)
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
