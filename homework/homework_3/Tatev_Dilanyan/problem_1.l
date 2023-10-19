D    [0-9]
L  [a-zA-Z_]
Op [+|*|-|/|%|=|<|>]
Del [{}();]

%{
#include <stdio.h>
%}
 
%%
if|else|while|for|int|double                        printf("Keyword=%s ", yytext);
[+-]?({D}+[.]{D}*)+"e"[+-]?{D}+         printf("Scientific notation=%s ", yytext); 
{L}({L}|{D})*                         printf("Identifier=%s ", yytext);
[+-]?{D}+                                       printf("Integer constant=%s ", yytext);
[+-]?({D}+[.]{D}*)|({D}*[.]{D}+)    printf("Floating point constant=%s ", yytext); 
{Op}+                                        printf("Operator=%s ", yytext);
{Del}+                                        printf("Delimeter=%s ", yytext);
.|\n {}
%% 

int main(void) { 
    yylex(); 
}

