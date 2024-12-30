#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool simulateNFA(const char *str) {
    int len = strlen(str);

    if (len >= 2 && str[0] == 'b' && str[len - 1] == 'a') {
        return true;
    }

    return false;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("The string '%s' is accepted by the NFA.\n", input);
    } else {
        printf("The string '%s' is not accepted by the NFA.\n", input);
    }

    return 0;
}

