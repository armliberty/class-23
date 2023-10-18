%{
#include <stdio.h>
%}

%%
"("    { printf("Delimiter: %s\n", yytext); }
")"    { printf("Delimiter: %s\n", yytext); }
";"    { printf("Delimiter: %s\n", yytext); }
"{"    { printf("Delimiter: %s\n", yytext); }
"}"    { printf("Delimiter: %s\n", yytext); }
. ;

%%

int main(void) {
    yylex();
    return 0;
}

