#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
#define HISTORY_LIMIT 4

int array[ARRAY_SIZE];
int history[HISTORY_LIMIT][ARRAY_SIZE];
int redo_history[HISTORY_LIMIT][ARRAY_SIZE];
int history_index = -1;
int redo_index = -1;

void printArray() {
    printf("Array: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void add(int index, int value) {
    if (index >= 0 && index < ARRAY_SIZE) {
        history_index++;
        if (history_index >= HISTORY_LIMIT) {
            for (int i = 0; i < HISTORY_LIMIT - 1; ++i) {
                for (int j = 0; j < ARRAY_SIZE; ++j) {
                    history[i][j] = history[i + 1][j];
                }
            }
            history_index = HISTORY_LIMIT - 1;
        }
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            history[history_index][i] = array[i];
        }
        array[index] += value;
        redo_index = -1;
    } else {
        printf("Index out of range.\n");
    }
}

void removeElement(int index, int value) {
    if (index >= 0 && index < ARRAY_SIZE) {
        history_index++;
        if (history_index >= HISTORY_LIMIT) {
            for (int i = 0; i < HISTORY_LIMIT - 1; ++i) {
                for (int j = 0; j < ARRAY_SIZE; ++j) {
                    history[i][j] = history[i + 1][j];
                }
            }
            history_index = HISTORY_LIMIT - 1;
        }
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            history[history_index][i] = array[i];
        }
        array[index] -= value;
        redo_index = -1;
    } else {
        printf("Index out of range.\n");
    }
}

void undo() {
    if (history_index >= 0) {
        redo_index++;
        if (redo_index >= HISTORY_LIMIT) {
            for (int i = 0; i < HISTORY_LIMIT - 1; ++i) {
                for (int j = 0; j < ARRAY_SIZE; ++j) {
                    redo_history[i][j] = redo_history[i + 1][j];
                }
            }
            redo_index = HISTORY_LIMIT - 1;
        }
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            redo_history[redo_index][i] = array[i];
        }
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            array[i] = history[history_index][i];
        }
        history_index--;
    } else {
        printf("Undo not possible.\n");
    }
}

void redo() {
    if (redo_index >= 0) {
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            array[i] = redo_history[redo_index][i];
        }
        redo_index--;
    } else {
        printf("Redo not possible.\n");
    }
}

int main() {
    // Initialize the array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = 0;
    }

    // Example usage
    add(2, 5);
    add(5, 8);
    printArray();

    removeElement(5, 3);
    printArray();

    undo();
    printArray();

    redo();
    printArray();

    return 0;
}

