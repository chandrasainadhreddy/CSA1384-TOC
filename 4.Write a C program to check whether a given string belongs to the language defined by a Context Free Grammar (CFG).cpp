#include <stdio.h>
#include <string.h>
int isCFGString(const char* str, int start, int end) {
    if (start > end) {
        return 1;
    }
    
    if (str[start] == '0' && str[end] == '0') {
        return isCFGString(str, start + 1, end - 1);
    }
    
    if (str[start] == '1' && str[end] == '1') {
        return isCFGString(str, start + 1, end - 1);
    }
    
    if (start == end && (str[start] == '0' || str[start] == '1')) {
        return 1;
    }
    
    return 0;
}

int main() {
    char input[100];
    printf("Enter a string to check: ");
    scanf("%s", input);
    
    int len = strlen(input);
    if (isCFGString(input, 0, len - 1)) {
        printf("The string belongs to the CFG language.\n");
    } else {
        printf("The string does not belong to the CFG language.\n");
    }
    
    return 0;
}

