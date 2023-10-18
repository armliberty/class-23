%{
#include <stdio.h>
%}

%%
(if|else|while|for|int|double)       printf("<%s, Keyword:> ", yytext);
[-+]?[0-9]+                        printf("<%s, Integer constants:> ", yytext);
([a-zA-Z0-9]+([._%+-]?[a-zA-Z0-9]+)*)+@[a-z.-]+\.[a-z]{2,}  printf("<%s, Email:> ", yytext);
[a-zA-Z_]+[a-zA-Z_0-9]+        printf("<%s, Identifiers:> ", yytext);
(__)?([+-]|\.)?[0-9]*[Ee]?[-+]?([0-9]+|\.)      printf("<%s, Floating point constants:>", yytext);
[+\-*/%=<>]=?|==|>=|<=        printf("<%s, Operators:>", yytext);
[();{}]            printf("<%s, Delimiters:>", yytext);
%%
