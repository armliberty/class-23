%{
#include <stdio.h>
%}

%%
[+-]?[0-9]*\.[0-9]+([eE][+-]?[0-9]+)? { printf("Float Constant: %s\n", yytext); }
. ;

%%

int main(void) {
    yylex();
    return 0;
}

