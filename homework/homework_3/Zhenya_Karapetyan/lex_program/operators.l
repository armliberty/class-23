%{
#include <stdio.h>
%}

%%
\+  printf("Plus sign: %s \n", yytext);
\-  printf("Minus sign: %s \n", yytext);
\*  printf("Asterisk: %s \n", yytext);
\/  printf("Slash: %s \n", yytext);
\%  printf("Percent sign: %s \n", yytext);
\=\=?  printf("Assign sign | Equals sign: %s \n", yytext);
\<\=?  printf("Smaller than | smaller than or equals to sign: %s \n", yytext);
\>\=?  printf("Greater than sign | Greater than or equals to sign: %s \n", yytext);
.|\n    {}
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}
