%{
#include <stdio.h>
#include <stdlib.h>

int char_count = 0, line_count = 0, word_count = 0;
%}

%%

[ \t]+          { char_count += yyleng; } 

"//".*          { char_count += yyleng; }  

"/*"([^*]|\*+[^*/])*("*/")? { char_count += yyleng; } 

\n              { line_count++; char_count++; }  

[a-zA-Z_][a-zA-Z0-9_]* { word_count++; char_count += yyleng; } 

[0-9]+          { word_count++; char_count += yyleng; }  

.               { char_count++; } 

%%

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);

    printf("Character Count: %d\n", char_count);
    printf("Word Count: %d\n", word_count);
    printf("Line Count: %d\n", line_count);
    return 0;
}

int yywrap() {
    return 1; 
}

