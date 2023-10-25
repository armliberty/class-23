%{
#include <stdio.h>
%}

%%
b*a?b+                            {printf("Count of Keywords: %s\n", "found");}
%%

int main() {
    yylex();

    return 0;
}