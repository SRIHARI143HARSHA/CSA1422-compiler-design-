#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char op[10];
    char arg1[10];
    char arg2[10];
    char result[10];
} ThreeAddressCode;

void generateThreeAddressCode(char *expression) {
    ThreeAddressCode code[MAX];
    int index = 0;
    char *token = strtok(expression, " ");
    
    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            strcpy(code[index].op, token);
            strcpy(code[index].arg1, strtok(NULL, " "));
            strcpy(code[index].arg2, strtok(NULL, " "));
            sprintf(code[index].result, "t%d", index);
            index++;
        }
        token = strtok(NULL, " ");
    }

    printf("Three Address Code:\n");
    for (int i = 0; i < index; i++) {
        printf("%s = %s %s %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);
    }
}

int main() {
    char expression[MAX];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; 
    generateThreeAddressCode(expression);
    return 0;
}

