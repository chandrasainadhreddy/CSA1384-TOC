#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool checkA(const char *str, int *index, int len) {
    while (*index < len && (str[*index] == '0' || str[*index] == '1')) {
        (*index)++;
    }
    return true; 
	}
bool checkS(const char *str, int len) {
    int index = 0;

    if (!checkA(str, &index, len)) {
        return false;
    }

    if (index + 2 < len && str[index] == '1' && str[index + 1] == '0' && str[index + 2] == '1') {
        index += 3;
    } else {
        return false;
    }

    if (!checkA(str, &index, len)) {
        return false;
    }

    return index == len;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    int len = strlen(input);

    if (checkS(input, len)) {
        printf("The string '%s' belongs to the CFG.\n", input);
    } else {
        printf("The string '%s' does not belong to the CFG.\n", input);
    }

    return 0;
}

