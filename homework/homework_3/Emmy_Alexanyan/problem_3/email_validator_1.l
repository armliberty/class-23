%{ 
#include <stdio.h> 
%} 
 
%% 
^([a-zA-Z0-9]+)([\.\-]*)([a-zA-Z0-9]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$  printf("Email is valid: %s\n",yytext); 
.|\n {ECHO;} 
 
 
 
%% 
 
int main(){ 
 
        printf("input text:"); 
        yylex(); 
 
} 


