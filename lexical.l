%{
#include <stdio.h>
%}

DIGIT       [0-9]
ID          [a-zA-Z_][a-zA-Z0-9_]*
WS          [ \t\n]+
OPERATOR    [+\-*/=<>]

%%

"if"        { printf("Keyword: %s\n", yytext); }
"else"      { printf("Keyword: %s\n", yytext); }
"while"     { printf("Keyword: %s\n", yytext); }
{ID}        { printf("Identifier: %s\n", yytext); }
{DIGIT}+    { printf("Number: %s\n", yytext); }
{OPERATOR}  { printf("Operator: %s\n", yytext); }
{WS}        { /* Ignore white spaces */ }
.           { printf("Unknown character: %s\n", yytext); }

%%

int main() {
    printf("Enter the input:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
