#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to simulate the DFA
bool simulateDFA(const char *str) {
    int len = strlen(str);

    // Check if the string starts with 'a' and ends with 'b'
    if (len >= 2 && str[0] == 'a' && str[len - 1] == 'b') {
        return true;
    }

    return false;
}

int main() {
    char input[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", input);

    // Simulate the DFA
    if (simulateDFA(input)) {
        printf("The string '%s' is accepted by the DFA.\n", input);
    } else {
        printf("The string '%s' is not accepted by the DFA.\n", input);
    }

    return 0;
}

