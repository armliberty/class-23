digit  [0-9]
letter [a-zA-Z]
sign [+-]
dot [.]
exp [eE]
delimiters [(|)|;|{|}]
operators [+|-|*|/|%|=|==|<|>|>=|<=]


%{
    #include <stdio.h>
%}

%%
(if|else|while|for|int|double) 			                printf("<%s, Keyword:> ", yytext);
{letter}{letter}*                                       printf("<%s, Keywords>\n", yytext);
({digit}+{letter}+)*|({letter}+{digit}+)*               printf("<%s, Identifier>\n", yytext);
{sign}?{digit}*                                         printf("<%s, Integer constants>\n", yytext);
{sign}?{digit}*{dot}{digit}*({exp}{sign}?{digit}+)?     printf("<%s,  Floating point constants>\n", yytext);
{operators}+                                            printf("<%s , Operators>\n", yytext);
{delimiters}+                                           printf("<%s, Delimiters>\n", yytext);
\n|\t {}

%%

int main(void) {
	yylex();
    return 0;    
}