#include <stdio.h>
#include <string.h>

// Global index to keep track of the current position in the string
int index = 0;

// Function to match A ? aA | bA | e
int matchA(char* str) {
    // Check for 'a', and recursively match A
    if (str[index] == 'a') {
        index++;  // Consume the character 'a'
        return matchA(str);  // Recurse for the next part of A
    }
    // Check for 'b', and recursively match A
    else if (str[index] == 'b') {
        index++;  // Consume the character 'b'
        return matchA(str);  // Recurse for the next part of A
    }
    // Match epsilon (empty string), i.e., end of string
    else if (str[index] == '\0') {
        return 1;  // Successfully matched empty string (e)
    }
    return 0;  // If neither 'a' nor 'b' and not end of string, it's an invalid match
}

int main() {
    char str[100];

    // Input the string to check
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string belongs to the language defined by the CFG
    if (matchA(str) && str[index] == '\0') {
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}

