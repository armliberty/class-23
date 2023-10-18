digits [0-9]
letters [a-zA-Z]
symbols [+._-]

%{
#include <stdio.h>
%}
 
%%

{letters}+{symbols}({letters}|{digits})*@({letters}|{digits}|-)+\.{letters}*    printf("Valid e-mail=%s ", yytext); 

.|\n {}
%% 

int main(void) { 
    yylex(); 
}
