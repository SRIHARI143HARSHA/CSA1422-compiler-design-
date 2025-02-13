#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 

const char *input;
int pos = 0;

void skipWhitespace() {
    while (isspace(input[pos])) {
        pos++;
    }
}

double parseNumber() {
    double value = 0;
    while (isdigit(input[pos])) {
        value = value * 10 + (input[pos] - '0');
        pos++;
    }
    if (input[pos] == '.') {
        pos++; 
        double decimalPlace = 0.1;
        while (isdigit(input[pos])) {
            value += (input[pos] - '0') * decimalPlace;
            decimalPlace *= 0.1;
            pos++;
        }
    }
    return value;
}

double parseFactor();

double parseExponentiation() {
    double result = parseFactor();
    skipWhitespace();
    while (input[pos] == '^') {
        pos++; 
        result = pow(result, parseFactor());
    }
    return result;
}

double parseTerm() {
    double result = parseExponentiation();
    skipWhitespace();
    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos++];
        double nextFactor = parseExponentiation();
        if (op == '*') {
            result *= nextFactor;
        } else {
            result /= nextFactor;
        }
    }
    return result;
}

double parseExpression() {
    double result = parseTerm();
    skipWhitespace();
    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos++];
        double nextTerm = parseTerm();
        if (op == '+') {
            result += nextTerm;
        } else {
            result -= nextTerm;
        }
    }
    return result;
}

double parseFactor() {
    skipWhitespace();
    double result;
    if (input[pos] == '(') {
        pos++;
        result = parseExpression();
        if (input[pos] == ')') {
            pos++;
        } else {
            printf("Error: Expected ')'\n");
            exit(1);
        }
    } else if (input[pos] == '-') { 
        pos++;
        result = -parseFactor();
    } else if (input[pos] == '+') {
        pos++;
        result = parseFactor();
    } else {
        result = parseNumber();
    }
    return result;
}

int main() {
    input = "3 + 5 * (2 - 8) ^ 2 / 4";
    printf("Input: %s\n", input);
    double result = parseExpression();
    skipWhitespace(); 
    if (input[pos] != '\0') {
        printf("Error: Unexpected character '%c' at position %d\n", input[pos], pos);
        return 1;
    }
    
    printf("The result of the expression is: %.2f\n", result);
    return 0;
}
