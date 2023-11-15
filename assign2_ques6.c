#include <stdio.h>
#include <stdbool.h>

bool is_operand(char character) {
    if (character >= '0' && character <= '9') {
        return true; // It is an operand
    } else {
        return false; // It is not an operand
    }
}

int main() {
    char test_char = '5';
    if (is_operand(test_char)) {
        printf("%c is an operand.\n", test_char);
    } else {
        printf("%c is not an operand.\n", test_char);
    }

    char another_char = '+';
    if (is_operand(another_char)) {
        printf("%c is an operand.\n", another_char);
    } else {
        printf("%c is not an operand.\n", another_char);
    }

    return 0;
}

