%{
#include <stdio.h>
%}

%%
"++"                   { printf("Operator: %s\n", yytext); }
"--"                   { printf("Operator: %s\n", yytext); }
[+\-*/%]               { printf("Operator: %s\n", yytext); }
"=="                   { printf("Operator: %s\n", yytext); }
"<="                   { printf("Operator: %s\n", yytext); }
">="                   { printf("Operator: %s\n", yytext); }
"="                    { printf("Operator: %s\n", yytext); }
"<"                    { printf("Operator: %s\n", yytext); }
">"                    { printf("Operator: %s\n", yytext); }
. ;

%%

int main(void) {
    yylex();
    return 0;
}

