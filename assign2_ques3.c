typedef struct {
    int items[MAX_SIZE];
    int top; // Initialize top to 0
} Stack;

void initializeStack(Stack *stack) {
    stack->top = 0; // Initializing top to 0
}

int isFull(Stack *stack, int size) {
    return stack->top == size;
}

int isEmpty(Stack *stack) {
    return stack->top == 0;
}

void push(Stack *stack, int data, int size) {
    if (isFull(stack, size)) {
        printf("Stack overflow!\n");
    } else {
        stack->items[stack->top++] = data; // Increment top after pushing
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        return stack->items[--stack->top]; // Decrement top before popping
    }
}

