%{ 
#include <stdio.h> 
%} 
 
%% 
"+"|"-"|"*"|"/"|"%"|"="|"=="|"<"|">"|"<="|">="  printf("Operator = %s\n",yytext); 
.|\n {} 
 
 
 
%% 
 
int main(){ 
 
        printf("input text:"); 
        yylex(); 
 
} 

