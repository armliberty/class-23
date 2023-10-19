%{
#include <stdio.h>
%}
 
%%

[A-Za-z0-9]+[.-_+][A-Za-z0-9]+@[A-Za-z0-9-]+\.[A-Za-z]{2,}     printf("Valid e-mail=%s ", yytext); 

.|\n {}
%% 

int main(void) { 
    yylex(); 
}
