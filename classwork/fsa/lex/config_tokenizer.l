%{
#include <stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9]*    printf("<%s, WORD> ", yytext);
[a-zA-Z0-9\/.-]+        printf("<%s, FILENAME> ", yytext);
\"                      printf("<%s, QUOTE> ", yytext);
\{                      printf("<%s, OBRACE> ", yytext);
\}                      printf("<%s, CBRACE> ", yytext);
;                       printf("<%s, SEMICOLON> ", yytext);
\n                      printf("\n");
[ \t]+                  /* ignore whitespace */;
%%
