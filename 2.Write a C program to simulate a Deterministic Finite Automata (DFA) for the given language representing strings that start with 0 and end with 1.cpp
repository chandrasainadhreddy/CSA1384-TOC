#include <stdio.h>
#include <string.h>
int isAccepted(char *str) {
    int state = 0; 

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        switch (state) {
            case 0: 
                if (ch == '0') 
                    state = 1;
                else 
                    state = 3; 
                break;
            case 1: 
                if (ch == '1') 
                    state = 2; 
                else if (ch != '0')
                    state = 3; 
                break;
            case 2: 
                if (ch == '1' || ch == '0') 
                    state = 2; 
                break;
            case 3: 
                return 0;
        }
    }

    return state == 2; 
}

int main() {
    char str[100];
    printf("Enter a binary string: ");
    scanf("%s", str);

    if (isAccepted(str)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }

    return 0;
}

