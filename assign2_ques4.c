#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char items[MAX_SIZE][MAX_NAME_LENGTH];
    int top;
} StringStack;

void initializeStringStack(StringStack *stack) {
    stack->top = 0;
}

int isStringStackFull(StringStack *stack) {
    return stack->top == MAX_SIZE;
}

int isStringStackEmpty(StringStack *stack) {
    return stack->top == 0;
}

void pushString(StringStack *stack, const char *name) {
    if (isStringStackFull(stack)) {
        printf("Stack overflow!\n");
    } else {
        strcpy(stack->items[stack->top++], name);
    }
}

char *popString(StringStack *stack) {
    if (isStringStackEmpty(stack)) {
        printf("Stack underflow!\n");
        return NULL;
    } else {
        return stack->items[--stack->top];
    }
}

void displayStringStack(StringStack *stack) {
    if (isStringStackEmpty(stack)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack contents:\n");
        for (int i = stack->top - 1; i >= 0; i--) {
            printf("%s\n", stack->items[i]);
        }
    }
}

int main() {
    StringStack namesStack;
    initializeStringStack(&namesStack);

    pushString(&namesStack, "Alice");
    pushString(&namesStack, "Bob");
    pushString(&namesStack, "Charlie");

    printf("Stack after pushing names:\n");
    displayStringStack(&namesStack);

    char *poppedName = popString(&namesStack);
    if (poppedName != NULL) {
        printf("Popped name: %s\n", poppedName);
        free(poppedName); // Free memory allocated by strdup
    }

    printf("Stack after popping a name:\n");
    displayStringStack(&namesStack);

    return 0;
}

