d [0-9]
l [a-zA-Z]
s [._-+]

%{ 
#include <stdio.h>
%}

%% 
 {l}+{s}({l}|{d})*@({l}|{d}|-)+\.{l}* { printf("Valid: %s\n", yytext); }
 

.|\n { 
 } 
%% 
 
int main() { 
    yylex(); 
    return 0; 
}