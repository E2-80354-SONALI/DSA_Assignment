#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;
int main()
{

}

void init_stack(stack *s)
{
 s->top = -1;
}

void push_stack(stack *s,int data)
{
//to increase the top
    s->top++;
    //to insert the data
    s->arr[s->top]=data;

}

void pop_stack(stack *s)
{
    s->arr[s->top]=0;
    s->top--;
}

int stack_full(stack *s,int data)
{
    return (s->top==SIZE-1);
}

int stack_empty(stack *s,int data)
{
    return (s->top == -1);
}

int stack_peek(stack *s,int data)
{
    s->arr[s->top];
}