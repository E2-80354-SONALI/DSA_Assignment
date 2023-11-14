#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack, int size) {
    return stack->top == size - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int data, int size) {
    if (isFull(stack, size)) {
        printf("Stack overflow!\n");
    } else {
        stack->items[++stack->top] = data;
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

// Queue implementation
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueFull(Queue *queue, int size) {
    return (queue->rear == size - 1 && queue->front == 0) || (queue->rear == queue->front - 1);
}

int isQueueEmpty(Queue *queue) {
    return queue->front == -1;
}

void enqueue(Queue *queue, int data, int size) {
    if (isQueueFull(queue, size)) {
        printf("Queue overflow!\n");
    } else {
        if (queue->rear == size - 1 && queue->front != 0) {
            queue->rear = -1;
        }
        queue->items[++queue->rear] = data;
        if (queue->front == -1) {
            queue->front = 0;
        }
    }
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    } else {
        int data = queue->items[queue->front++];
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return data;
    }
}

int main() {
    int size;
    printf("Enter the size for stack and queue: ");
    scanf("%d", &size);

    Stack stack;
    Queue queue;

    initializeStack(&stack);
    initializeQueue(&queue);

    printf("\nStack operations:\n");
    for (int i = 0; i < size; i++) {
        push(&stack, i + 1, size);
    }
    printf("Popping elements from the stack: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    printf("\nQueue operations:\n");
    for (int i = 0; i < size; i++) {
        enqueue(&queue, i + 1, size);
    }
    printf("Dequeueing elements from the queue: ");
    while (!isQueueEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}


