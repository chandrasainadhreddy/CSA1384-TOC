#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to simulate the NFA
bool simulateNFA(const char *str) {
    int len = strlen(str);

    // Check if the string starts with '1' and ends with '1'
    if (len >= 2 && str[0] == '1' && str[len - 1] == '1') {
        return true;
    }

    return false;
}

int main() {
    char input[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", input);

    // Simulate the NFA
    if (simulateNFA(input)) {
        printf("The string '%s' is accepted by the NFA.\n", input);
    } else {
        printf("The string '%s' is not accepted by the NFA.\n", input);
    }

    return 0;
}

