%{ 
#include <stdio.h> 
%} 
 
%% 
[-+]?[0-9]*[e]?[.][e]?[0-9]+  printf("Floating point constant = %s\n",yytext); 
.|\n {} 
 
 
 
%% 
 
int main(){ 
 
        printf("input text:"); 
        yylex(); 
 
} 

