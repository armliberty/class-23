%{ 
#include <stdio.h> 
%} 
 
%% 
[0-9]*  printf("integer = %s\n",yytext); 
\+[0-9]*  printf("integer = %s\n",yytext); 
\-[0-9]*  printf("integer = %s\n",yytext); 
.|\n {} 
 
 
 
%% 
 
int main(){ 
 
        printf("input text:"); 
        yylex(); 
 
} 

