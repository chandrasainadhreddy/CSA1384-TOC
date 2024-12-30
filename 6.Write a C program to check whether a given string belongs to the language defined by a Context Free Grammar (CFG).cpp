#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
bool checkCFG(const char *str, int start, int end) {
     
    if (start > end) {
        return true;
    }
 
    if (str[start] == '0' && str[end] == '1') {
        return checkCFG(str, start + 1, end - 1);
    }

    return false;
}

int main() {
    char input[100];
 
    printf("Enter a string of 0s and 1s: ");
    scanf("%s", input);
 
    int len = strlen(input);

    if (checkCFG(input, 0, len - 1)) {
        printf("The string '%s' belongs to the CFG.\n", input);
    } else {
        printf("The string '%s' does not belong to the CFG.\n", input);
    }

    return 0;
}

