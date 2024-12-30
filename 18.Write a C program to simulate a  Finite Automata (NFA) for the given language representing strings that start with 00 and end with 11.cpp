#include <stdio.h>
#include <string.h>

// Function to simulate the NFA
int simulateNFA(char* str) {
    int length = strlen(str);
    int state = 0; // Initial state q0

    for (int i = 0; i < length; i++) {
        char currentChar = str[i];

        switch (state) {
            case 0: // Initial state q0
                if (currentChar == '0') {
                    state = 1;  // Transition to q1 after reading 0
                } else {
                    return 0;  // Reject if the string doesn't start with '0'
                }
                break;

            case 1: // State q1 after reading the first '0'
                if (currentChar == '0') {
                    state = 2;  // Transition to q2 after reading second '0'
                } else {
                    return 0;  // Reject if the second character isn't '0'
                }
                break;

            case 2: // State q2 after reading '00'
                if (currentChar == '0' || currentChar == '1') {
                    state = 2;  // Stay in q2 and consume any character (0 or 1)
                } else {
                    return 0;  // Reject if any other character is encountered
                }
                break;

            case 3: // State q3 after reading a '1' in the middle
                if (currentChar == '1') {
                    state = 4;  // Transition to accepting state q4 after reading second '1'
                } else {
                    return 0;  // Reject if the character isn't '1'
                }
                break;

            case 4: // State q4 (accepting state)
                return 0;  // If we are in state q4, and there's more input, reject

            default:
                return 0;  // Reject for any undefined state
        }
    }

    // If the string ends in state q4, it's accepted
    if (state == 4) {
        return 1;  // Accept the string if it ends in the accepting state (q4)
    } else {
        return 0;  // Reject the string if it doesn't end in q4
    }
}

int main() {
    char str[100];

    // Input the string to check
    printf("Enter a string: ");
    scanf("%s", str);

    // Simulate the NFA and check if the string belongs to the language
    if (simulateNFA(str)) {
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}

