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

// Function to match S ? aAb
int matchS(char* str) {
    if (str[index] == 'a') {
        index++;  // Consume the 'a' at the beginning
        if (matchA(str)) {  // Match A
            if (str[index] == 'b') {
                index++;  // Consume the 'b' at the end
                return 1;  // Successfully matched S ? aAb
            }
        }
    }
    return 0;  // If the structure does not match, return 0
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

