%{
#include <stdio.h>
%}

%%
if     { printf("Keyword: if\n"); }
else   { printf("Keyword: else\n"); }
while  { printf("Keyword: while\n"); }
for    { printf("Keyword: for\n"); }
int    { printf("Keyword: int\n"); }
double { printf("Keyword: double\n"); }


%%

int main(void) {
    yylex();
    return 0;
}
