#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 30

int isOperator(char ch) {
    char operators[] = "+-*/%=<>!";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i]) return 1;
    }
    return 0;
}
void lexicalAnalyzer(char *code) {
    int i = 0, len = strlen(code);
    
    while (i < len) {
       
        if (isspace(code[i])) {
            i++;
            continue;
        }

        if (code[i] == '/' && code[i + 1] == '/') {
            while (i < len && code[i] != '\n') i++;
            continue;
        }

        if (code[i] == '/' && code[i + 1] == '*') {
            i += 2;
            while (i < len - 1 && !(code[i] == '*' && code[i + 1] == '/')) i++;
            i += 2;
            continue;
        }

        
        if (isalpha(code[i]) || code[i] == '_') {
            char identifier[MAX_ID_LEN + 1];
            int idIndex = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                if (idIndex < MAX_ID_LEN) {
                    identifier[idIndex++] = code[i];
                }
                i++;
            }
            identifier[idIndex] = '\0';
            printf("Identifier: %s\n", identifier);
        }
        else if (isdigit(code[i])) { 
          
            char number[20];
            int numIndex = 0;
            while (isdigit(code[i])) {
                number[numIndex++] = code[i++];
            }
            number[numIndex] = '\0';
            printf("Constant: %s\n", number);
        }
        else if (isOperator(code[i])) {
          
            printf("Operator: %c\n", code[i]);
            i++;
        }
        else {
          
            i++;
        }
    }
}
int main() {
    char code[500];

    printf("Enter code: ");
    fgets(code, sizeof(code), stdin);

    lexicalAnalyzer(code);

    return 0;
}

