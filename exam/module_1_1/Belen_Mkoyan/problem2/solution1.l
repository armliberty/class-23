
%{
#include <stdio.h>
%}

%%

 ([a-zA-Z][0-9][._-+])*a?b+ { printf("Valid: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}