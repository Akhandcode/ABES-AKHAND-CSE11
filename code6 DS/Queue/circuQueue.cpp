#include <iostream>
#include <stdlib.h>
#define MAXQUEUE 10

using namespace std;

struct Queue
{
    char item[MAXQUEUE];
    int REAR;
    int FRONT;
};

void Initialise(Queue *Q)
{
    Q->REAR=MAXQUEUE;
    Q->FRONT=MAXQUEUE;
}
int enqueue(Queue *Q,int x)
{
    if((Q->REAR+1)%MAXQUEUE==Q->FRONT)
    {
     cout<<"Overflow Queue";
     exit(1);
    }
    else
    {
      Q->REAR=Q->REAR+1;
      Q->item[Q->REAR]=x;
    }
}

bool isEmpty(Queue *Q)
{
    if((Q->REAR-Q->FRONT+1)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dequeue(Queue *Q)
{
    if(isEmpty(Q))
    {
     cout<<"Queue Underflow";
     exit(1);
    }
    else
    {
        char x=Q->item[Q->FRONT];
        Q->FRONT=Q->FRONT+1;
        return x;
    }
}

int main()
{
    Queue Q;
    Initialise(&Q);
    enqueue(&Q,'A');
    enqueue(&Q,'B');
    enqueue(&Q,'C');
    enqueue(&Q,'D');
    enqueue(&Q,'E');

    char x=dequeue(&Q);
    cout<<"Deleted item :-"<<x<<"\n";
    x=dequeue(&Q);
    cout<<"Deleted item :-"<<x<<"\n";
    x=dequeue(&Q);
    cout<<"Deleted item :-"<<x<<"\n";
    x=dequeue(&Q);
}






