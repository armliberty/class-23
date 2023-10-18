%{
#include <stdio.h>
%}

%%
"while"|"if"|"else"|"for"|"int"|"double" {printf("\t token is: %s", yytext);}
.|\n {}
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}
