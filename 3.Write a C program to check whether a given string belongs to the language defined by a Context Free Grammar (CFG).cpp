#include <stdio.h>
#include <string.h>

int index = 0; // Global index to track position in the string

// Function to parse A
int parseA(const char *str) {
    // A can produce 0A, 1A, or e
    while (str[index] == '0' || str[index] == '1') {
        index++; // Consume the character
        if (str[index - 1] == '0' || str[index - 1] == '1') {
            // Continue parsing A
            parseA(str);
        }
    }
    return 1; // Successfully parsed A
}

// Function to parse S
int parseS(const char *str) {
    if (str[index] == '0') {
        index++; // Consume '0'
        if (parseA(str)) { // Parse A
            if (str[index] == '1') {
                index++; // Consume '1'
                return 1; // Successfully parsed S
            }
        }
    }
    return 0; // Failed to parse S
}

int main() {
    char str[100];
    printf("Enter a string of 0s and 1s: ");
    scanf("%s", str);

    // Reset index for parsing
    index = 0;

    // Check if the entire string is parsed successfully
    if (parseS(str) && index == strlen(str)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }

    return 0;
}
