%{
#include <stdio.h>
%}

%%
"("     printf("Delimiter: ( \n");
")"     printf("Delimiter: ) \n");
";"     printf("Delimiter: ; \n");
"{"     printf("Delimiter: { \n");
"}"     printf("Delimiter: } \n");
%%

int yywrap(void){}

int main() {
    yylex();
    return 0;
}
