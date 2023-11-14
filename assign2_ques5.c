#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
    int pages;
} Book;

typedef struct {
    Book items[MAX_SIZE];
    int top;
} BookStack;

void initializeBookStack(BookStack *stack) {
    stack->top = -1;
}

int isBookStackFull(BookStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isBookStackEmpty(BookStack *stack) {
    return stack->top == -1;
}

void pushBook(BookStack *stack, const char *name, const char *author, float price, int pages) {
    if (isBookStackFull(stack)) {
        printf("Stack overflow!\n");
    } else {
        stack->top++;
        strncpy(stack->items[stack->top].name, name, MAX_NAME_LENGTH - 1);
        stack->items[stack->top].name[MAX_NAME_LENGTH - 1] = '\0';
        strncpy(stack->items[stack->top].author, author, MAX_AUTHOR_LENGTH - 1);
        stack->items[stack->top].author[MAX_AUTHOR_LENGTH - 1] = '\0';
        stack->items[stack->top].price = price;
        stack->items[stack->top].pages = pages;
    }
}

Book popBook(BookStack *stack) {
    Book emptyBook = { .name = "", .author = "", .price = 0.0f, .pages = 0 };

    if (isBookStackEmpty(stack)) {
        printf("Stack underflow!\n");
        return emptyBook;
    } else {
        Book poppedBook = stack->items[stack->top];
        stack->top--;
        return poppedBook;
    }
}

void displayBook(Book book) {
    printf("Name: %s\n", book.name);
    printf("Author: %s\n", book.author);
    printf("Price: %.2f\n", book.price);
    printf("Pages: %d\n", book.pages);
    printf("\n");
}

int main() {
    BookStack books;
    initializeBookStack(&books);

    pushBook(&books, "Book1", "Author1", 19.99f, 300);
    pushBook(&books, "Book2", "Author2", 24.99f, 400);
    pushBook(&books, "Book3", "Author3", 14.99f, 250);

    printf("Books after pushing:\n");
    for (int i = books.top; i >= 0; i--) {
        displayBook(books.items[i]);
    }

    Book popped = popBook(&books);
    if (strcmp(popped.name, "") != 0) {
        printf("Popped book:\n");
        displayBook(popped);
    }

    printf("Books after popping:\n");
    for (int i = books.top; i >= 0; i--) {
        displayBook(books.items[i]);
    }

    return 0;
}

