%{
#include <stdio.h>
%}

integers {integers}

%%
(\+|\-)?{integers}*\.{integers}+(e(\+|\-)?{integers}+)? | (\+|\-)?{integers}+\.{integers}*(e(\+|\-)?{integers}+)? | 
(\+|\-)?{integers}+\.{integers}*(e(\+|\-)?{integers}+) | (\+|\-)?\.{integers}+(e(\+|\-)?{integers}+)? | 
(\+|\-)?{integers}+\.(e(\+|\-)?{integers}+)? | (\+|\-)?{integers}*(e(\+|\-)?{integers}+)    printf("Floating point constant: %s\n", yytext);
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}
