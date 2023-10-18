%{ 
#include <stdio.h> 
%} 
 
%% 
[a-zA-Z0-9\_][a-zA-Z0-9]*  printf("identifier = %s\n",yytext); 
.|\n {} 
 
 
 
%% 
 
int main(){ 
 
        printf("input text:"); 
        yylex(); 
 
} 

