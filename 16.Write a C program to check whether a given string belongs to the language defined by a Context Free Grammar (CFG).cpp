#include <stdio.h>
#include <string.h>

int index = 0;  // Global index to keep track of the current position in the string

// Function to match A ? 0A | 1A | e
int matchA(char* str) {
    if (str[index] == '0' || str[index] == '1') {
        index++;  // Consume the character
        return matchA(str);  // Recurse for the next part of A
    } else if (str[index] == '\0') {
        return 1;  // Match epsilon (empty string)
    }
    return 0;  // If neither '0', '1', nor end of string, it's an invalid match
}

// Function to match S ? A00A
int matchS(char* str) {
    int startIndex = index;

    // Match the first A
    if (!matchA(str)) {
        index = startIndex;  // Backtrack if the first A doesn't match
        return 0;
    }

    // Check if we have "00" in the middle
    if (str[index] == '0' && str[index + 1] == '0') {
        index += 2;  // Consume "00"
    } else {
        return 0;  // If "00" is not found, it's an invalid match
    }

    // Match the second A
    if (!matchA(str)) {
        return 0;  // If the second A doesn't match, it's an invalid match
    }

    return 1;  // Successfully matched S ? A00A
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

