#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_ALPHABET 10

// Structure to represent a transition table
struct NFA {
    int states[MAX_STATES][MAX_ALPHABET];  // Transition table
    int epsilon[MAX_STATES][MAX_STATES];    // Epsilon transitions
    int numStates;
    int numAlphabet;
};

// Function to find epsilon closure for a state
void epsilonClosure(struct NFA *nfa, int state, int closure[MAX_STATES], int *closureSize) {
    // Initialize the closure array and add the state
    closure[*closureSize] = state;
    (*closureSize)++;

    // Process the epsilon transitions for the current state
    for (int i = 0; i < nfa->numStates; i++) {
        if (nfa->epsilon[state][i] == 1) { // If there's an epsilon transition from 'state' to 'i'
            // Check if state 'i' is already in closure, if not, add it
            int isPresent = 0;
            for (int j = 0; j < *closureSize; j++) {
                if (closure[j] == i) {
                    isPresent = 1;
                    break;
                }
            }
            if (!isPresent) {
                epsilonClosure(nfa, i, closure, closureSize);
            }
        }
    }
}

// Function to print the epsilon closure for all states
void printEpsilonClosures(struct NFA *nfa) {
    int closure[MAX_STATES];
    int closureSize;

    for (int state = 0; state < nfa->numStates; state++) {
        closureSize = 0;
        printf("e-closure(%d) = {", state);
        epsilonClosure(nfa, state, closure, &closureSize);

        // Print the closure for the current state
        for (int i = 0; i < closureSize; i++) {
            printf("%d", closure[i]);
            if (i < closureSize - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

int main() {
    struct NFA nfa;
    
    // Example NFA with 5 states and e-transitions
    nfa.numStates = 5;
    nfa.numAlphabet = 2; // Alphabet size (can be extended for more symbols)

    // Define e-transitions: 1 means epsilon transition exists
    // Format: nfa.epsilon[from_state][to_state] = 1
    // Example: nfa.epsilon[0][1] = 1 means an epsilon transition from state 0 to state 1
    nfa.epsilon[0][1] = 1;
    nfa.epsilon[1][2] = 1;
    nfa.epsilon[2][3] = 1;
    nfa.epsilon[3][4] = 1;
    nfa.epsilon[1][4] = 1;

    // Initialize all other transitions to 0
    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < MAX_STATES; j++) {
            if (i != j) {
                nfa.epsilon[i][j] = 0;
            }
        }
    }

    // Print epsilon closures for all states
    printEpsilonClosures(&nfa);

    return 0;
}

