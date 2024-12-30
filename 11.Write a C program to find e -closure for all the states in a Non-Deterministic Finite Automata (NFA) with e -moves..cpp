#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 100

// Function to find epsilon-closure for a given state
void findEpsilonClosure(int nfa[MAX_STATES][MAX_STATES], int state, bool visited[MAX_STATES], int closure[MAX_STATES], int *closureSize) {
    // Mark the current state as visited
    visited[state] = true;

    // Add the state to the epsilon-closure
    closure[(*closureSize)++] = state;

    // Explore all epsilon transitions
    for (int i = 0; i < MAX_STATES; i++) {
        if (nfa[state][i] == -1 && !visited[i]) { // -1 represents an epsilon move
            findEpsilonClosure(nfa, i, visited, closure, closureSize);
        }
    }
}

int main() {
    int nfa[MAX_STATES][MAX_STATES];
    int numStates;

    // Initialize the NFA transition table
    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < MAX_STATES; j++) {
            nfa[i][j] = 0; // 0 indicates no transition
        }
    }

    // Input the number of states
    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    // Input the transitions
    printf("Enter transitions (-1 for epsilon moves, 0 for no move):\n");
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            printf("Transition from state %d to state %d: ", i, j);
            scanf("%d", &nfa[i][j]);
        }
    }

    // Compute epsilon-closures for all states
    for (int state = 0; state < numStates; state++) {
        bool visited[MAX_STATES] = {false};
        int closure[MAX_STATES];
        int closureSize = 0;

        findEpsilonClosure(nfa, state, visited, closure, &closureSize);

        // Print the epsilon-closure for the current state
        printf("Epsilon-closure of state %d: ", state);
        for (int i = 0; i < closureSize; i++) {
            printf("%d ", closure[i]);
        }
        printf("\n");
    }

    return 0;
}

