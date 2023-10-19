letter [a-zA-Z_]
digit [0-9]

%{
#include <stdio.h>
%}

%%

"if"      { printf("Keyword: if\n"); }
"else"    { printf("Keyword: else\n"); }
"while"   { printf("Keyword: while\n"); }
"for"     { printf("Keyword: for\n"); }
"int"     { printf("Keyword: int\n"); }
"double"  { printf("Keyword: double\n"); }

{letter}({digit}|{letter})* { printf("Identifier: %s\n", yytext); }
  
[+-]?{digit}+ { printf("Integer constant : %s\n", yytext); }

[-+]?({digit}+|{digit}*\.{digit}+|{digit}+\.{digit}*)([eE][-+]?{digit}+)? { printf("Float: %s\n",yytext); }

\+|\-|\*|\=|\<|\>|\/|\%|\=\=|\>\=|\<\=  {printf("Operator: %s\n", yytext); }

[(){};] { printf("Delimiters: %s\n",yytext); }

%%

int main() {
    yylex();
    return 0;
}