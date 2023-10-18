%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }
[0-9][a-zA-Z0-9_]*     { /* Ignore identifiers starting with a digit */ }
. ;

%%

int main(void) {
    yylex();
    return 0;
}

