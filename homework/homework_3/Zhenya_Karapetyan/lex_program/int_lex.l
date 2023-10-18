%{
#include <stdio.h>
%}

integers [0-9]

%%
(\+|\-)?{integers}+ printf("Integer constant: %s \n", yytext);
.|\n    {}
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}
