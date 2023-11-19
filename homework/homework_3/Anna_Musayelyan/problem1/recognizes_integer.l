%{
#include <stdio.h>
%}

%%
[+-]?[0-9]+ { printf("Integer Constant: %s\n", yytext); }
. ;

%%

int main(void) {
    yylex();
    return 0;
}


