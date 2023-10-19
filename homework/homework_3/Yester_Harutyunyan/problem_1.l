digit    [0-9]
letter  [a-zA-Z_]
operators [+|*|-|/|%|=|<|>]
delimiter [{}();]

%{
#include <stdio.h>
%}

%%
if|else|while|for|int|double                        printf("Keyword=%s ", yytext);
[+-]?({digit}+[.]{digit}*)+"e"[+-]?{digit}+         printf("Scientific notation=%s ", yytext); 
{letter}({letter}|{digit})*                         printf("Identifier=%s ", yytext);
[+-]?{digit}+                                       printf("Integer constant=%s ", yytext);
[+-]?({digit}+[.]{digit}*)|({digit}*[.]{digit}+)    printf("Floating point constant=%s ", yytext); 
{operators}+                                        printf("Operator=%s ", yytext);
{delimiter}+                                        printf("Delimeter=%s ", yytext);
.|\n {}
%% 

int main(void) { 
    yylex(); 
}