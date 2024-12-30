#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isValid(const char *str, int start, int end) {
    if (start > end) return true;

    if (str[start] == '0' && str[end] == '0') {
        return isValid(str, start + 1, end - 1);
    }

    if (str[start] == '1') {
        return isValid(str, start + 1, end);
    }

    return false;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);

    if (isValid(input, 0, length - 1)) {
        printf("The string '%s' belongs to the language defined by the CFG.\n", input);
    } else {
        printf("The string '%s' does not belong to the language defined by the CFG.\n", input);
    }

    return 0;
}

