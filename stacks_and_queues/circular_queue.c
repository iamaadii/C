#include <stdio.h>
#define size 3
int queue[size];
int rear = -1;
int front = -1;

void enqueue(int element)
{
  if (rear == -1 && front == -1)
  {
    ++front;
    queue[++rear] = element;
  }

  else if ((rear + 1) % size == front)
    printf("overflow\n");

  else
  {
    rear = (rear + 1) % size;
    queue[rear] = element;
  }
}

void dequeue()
{
  if (rear == -1 && front == -1)
    printf("\nunderflow");

  else if (rear == front)
  {
    printf("%d deleted\n", queue[front]);
    front = -1;
    rear = -1; 
  }
  else
  {
    printf("%d deleted\n", queue[front]);
    front = (front + 1) % size;
  }
}

void print()
{
  if (rear == -1 && front == -1)
    printf("\nunderflow");
  else
  {
    int i = front;
    while (i != rear)
    {
      printf("%d\n", queue[i]);
      i = (i + 1) % size;
    }
    printf("%d\n", queue[rear]);
  }
}

int main()
{
  int choice, data, key;
  printf("\nenter 1 for enqueue");
  printf("\nenter 2 for dequeue");
  printf("\nenter 3 for print");
  printf("\nEnter any other number for exit");
  while (1)
  {
    printf("\nenter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("enter data : ");
      scanf("%d", &data);
      enqueue(data);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      print();
      break;
    default:
      printf("wrong choice\n");
      return 0;
    }
  }
}
