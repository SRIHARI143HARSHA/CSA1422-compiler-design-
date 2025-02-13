#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char *productions[], int n) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == productions[i][3]) { // Check for left recursion
            printf("Eliminating left recursion for production: %s\n", productions[i]);
            // Create new production
            printf("%c -> %s%c'\n", productions[i][0], &productions[i][3], productions[i][0]);
            printf("%c' -> %s%c' | e\n", productions[i][0], &productions[i][3], productions[i][0]);
        } else {
            printf("%s\n", productions[i]); // No left recursion
        }
    }
}

int main() {
    char *productions[] = {"A -> A alpha | beta", "B -> beta"};
    int n = sizeof(productions) / sizeof(productions[0]);
    eliminateLeftRecursion(productions, n);
    return 0;
}
