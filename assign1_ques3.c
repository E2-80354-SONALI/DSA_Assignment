#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void printStudents(struct Student students[], int size) {
    printf("Roll No\tName\tMarks\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(struct Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (students[j].marks < students[minIndex].marks) {
                minIndex = j;
            }
        }
        swap(&students[i], &students[minIndex]);
    }
}

int main() {
    struct Student students[MAX_STUDENTS] = {
        {101, "Alice", 78.5},
        {102, "Bob", 92.0},
        {103, "Charlie", 85.5},
        {104, "David", 60.0},
        {105, "Eva", 75.5},
        {106, "Frank", 88.0},
        {107, "Grace", 95.5},
        {108, "Harry", 70.0},
        {109, "Ivy", 83.5},
        {110, "Jack", 79.0}
    };

    printf("Before Sorting:\n");
    printStudents(students, MAX_STUDENTS);

    // Sort students based on marks
    selectionSort(students, MAX_STUDENTS);

    printf("\nAfter Sorting by Marks:\n");
    printStudents(students, MAX_STUDENTS);

    return 0;
}


