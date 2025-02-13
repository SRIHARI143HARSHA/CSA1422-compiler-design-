#include <stdio.h>
#include <string.h>
#include <ctype.h>

int index = 0;
char input[100];

int isValidSentence();
int isValidNounPhrase();
int isValidVerbPhrase();

int isValidSentence() {
    if (isValidNounPhrase()) {
        if (input[index] == ' ') {
            index++;
            if (isValidVerbPhrase()) {
                return 1;
            }
        }
    }
    return 0;
}

int isValidNounPhrase() {
    if (isalpha(input[index])) {
        while (isalpha(input[index])) {
            index++;
        }
        return 1;
    }
    return 0;
}

int isValidVerbPhrase() {
    if (isalpha(input[index])) {
        while (isalpha(input[index])) {
            index++;
        }
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 

    if (isValidSentence() && input[index] == '\0') {
        printf("The sentence is grammatically correct.\n");
    } else {
        printf("The sentence is grammatically incorrect.\n");
    }
    return 0;
}

