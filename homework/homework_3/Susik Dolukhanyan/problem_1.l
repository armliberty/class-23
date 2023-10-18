digit    [0-9] 
letter   [a-zA-Z_] 
%{ 
#include <stdio.h> 
%} 
 
%%
if|else|while|for|int|double                     printf("Keyword=%s", yytext);
{letter}({letter}|{digit})*                      printf("Identifier=%s", yytext);
"+"|"-"|[*/.]|[%=]|"=="|[<>]|"<="|">="            printf("Operator=%s", yytext);
[+-]?{digit}+                                    printf("Integer constant=%s", yytext);
[+-]?({digit}*[.]?{digit}*([eE][-+]?{digit}+)?)  printf("Floating point constant=%s", yytext); 
[();{}]                                          printf("Delimeter=%s", yytext);
.|\n {}
%% 

int main(void) { 
    yylex(); 
}
