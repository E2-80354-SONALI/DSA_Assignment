#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct queue{
    int arr[SIZE];
    int rear;
    int front;
}queue;
void init_queue(queue *pq);
void enqueue(queue *pq,int data);
void dequeue(queue *pq);
int queue_empty(queue *pq);
int queue_full(queue *pq);
int get_front(queue *pq);
void del_specific(int data,int pos);

int main()
{
    int choice,data;
    queue Q;
    init_queue(&Q);
do{
    printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n");
    printf("Enter the choice:\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: 
                    if(queue_full(&Q))
                        printf("queue is full!\n");
                    else
                    {
                        printf("Enter the element:\n");
                        scanf("%d",&data);
                        enqueue(&Q,data);
                        printf("Data inserted successfully!\n");
                    } 
                    break;
            case 2:
                    if(queue_empty(&Q))
                        printf("queue is empty!\n");
                    else
                    {
                        int ele;
                        ele = get_front(&Q);
                        dequeue(&Q);
                        printf("\nElement deleted=%d",ele);
                    }
                    break;
                default:
                    printf("Please enter the valid choice!");
        }
}while(choice!=0);
    return 0;
}
//for intialize the queue
void init_queue(queue *pq)
{
    //to intialize the rear
    pq->rear = -1;
    //to initialize the front
    pq->front=-1;
}

//for enque the queue
void enqueue(queue *pq,int data)
{
    //to increase the rear
    pq->rear = (pq->rear+1)%SIZE;
    //to initialize the elements
    pq->arr[pq->rear]=data;
    //to set the index of the front from -1 to 0
    if(pq->front == -1)
        pq->front = 0;

}
void dequeue(queue *pq)
{
    //for 
    if(pq->front == pq->rear)
    {
        pq-> front = pq->rear = -1;
    }
    else
    {
        pq->arr[pq->front]=0;
        pq->front=(pq->front+1)%SIZE;

    }

}

int queue_empty(queue *pq)
{
    return (pq->rear ==-1);
}

int queue_full(queue *pq)
{
    return (pq->front == (pq->rear+1)%SIZE);
}

int get_front(queue *pq)
{
    return pq->arr[pq->front];
}

void del_specific(int data,int pos)
{

}