#include <stdio.h>
#include <string.h>

int index = 0;  // Global index to keep track of the current position in the string

// Function to match A ? aA | bA | e
int matchA(char* str) {
    if (str[index] == 'a') {
        index++;  // Consume the character 'a'
        return matchA(str);  // Recurse for the next part of A
    } else if (str[index] == 'b') {
        index++;  // Consume the character 'b'
        return matchA(str);  // Recurse for the next part of A
    } else if (str[index] == '\0') {
        return 1;  // Match epsilon (empty string)
    }
    return 0;  // If neither 'a', 'b', nor end of string, it's an invalid match
}

// Function to match S ? AaAaA
int matchS(char* str) {
    int startIndex = index;

    // Match first A
    if (!matchA(str)) {
        return 0;  // If the first A doesn't match, return 0
    }

    // Check for 'a'
    if (str[index] == 'a') {
        index++;  // Consume the 'a'
    } else {
        return 0;  // If 'a' is not found, return 0
    }

    // Match second A
    if (!matchA(str)) {
        return 0;  // If the second A doesn't match, return 0
    }

    // Check for 'a'
    if (str[index] == 'a') {
        index++;  // Consume the 'a'
    } else {
        return 0;  // If 'a' is not found, return 0
    }

    // Match third A
    if (!matchA(str)) {
        return 0;  // If the third A doesn't match, return 0
    }

    return 1;  // Successfully matched S ? AaAaA
}

int main() {
    char str[100];

    // Input the string to check
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string belongs to the language defined by the CFG
    if (matchS(str) && str[index] == '\0') {
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}

