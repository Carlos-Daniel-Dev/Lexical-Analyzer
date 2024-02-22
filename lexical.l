%{
#include <stdio.h>
%}

%%

[0-9]+                  { printf("Integer: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*    { printf("Identifier: %s\n", yytext); }
[-+*/]                  { printf("Operator: %c\n", yytext[0]); }
[\n]                    { /* Do nothing, just consume the newline */ }
[ \t]                   { /* Do nothing, just consume spaces and tabs */ }

.                       { printf("Unrecognized character: %c\n", yytext[0]); }

%%

int main() {
    yylex();
    return 0;
}
