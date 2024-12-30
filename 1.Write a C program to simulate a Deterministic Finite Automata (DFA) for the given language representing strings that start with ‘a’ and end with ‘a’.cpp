#include <stdio.h>
#include <string.h>
int isAccepted(char *str) {
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        switch (state) {
            case 0:
                state = (ch == 'a') ? 1 : 3;
                break;
            case 1:
                state = (ch == 'a') ? 2 : 1;
                break;
            case 2:
                state = (ch == 'a') ? 2 : 1;
                break;
            case 3:
                return 0; 
        }
    }
    return state == 2; 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isAccepted(str)) {
        printf("String is accepted by the DFA.\n");
    } else {
        printf("String is rejected by the DFA.\n");
    }
    return 0;
}

