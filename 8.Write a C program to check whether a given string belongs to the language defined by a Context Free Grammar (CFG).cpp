#include <stdio.h>
#include <string.h>

char input[100];  // Input string
int index = 0;    // Pointer to the current character in the input string

// Function to match a character and move the index forward
int match(char expected) {
    if (input[index] == expected) {
        index++;  // Move to the next character
        return 1;
    }
    return 0;
}

// Recursive descent parser function for the start symbol (S)
int S() {
    if (match('a')) {  // Try to match 'a'
        if (S()) {  // Recurse
            if (match('b')) {  // Try to match 'b'
                return 1;  // Successfully matched aSb
            }
        }
    } else {
        // If we can't match 'a', check for the empty string (ε)
        return 1;  // ε production
    }
    return 0;  // If no match found, return failure
}

int main() {
    printf("Enter a string to check if it belongs to the language: ");
    scanf("%s", input);

    // Call the parser for the start symbol S
    if (S() && input[index] == '\0') {  // Ensure entire string is consumed
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}
