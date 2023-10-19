%{ 
#include <stdio.h> 
%} 
 
%% 
\(  printf("Delimiter: %s\n", yytext);
\)  printf("Delimiter: %s\n", yytext);
\;  printf("Delimiter: %s\n", yytext);
\{  printf("Delimiter: %s\n", yytext);
\}  printf("Delimiter: %s\n", yytext); 
.|\n {} 
 
 
 
%% 
 
int main(){ 
 
        printf("input text:"); 
        yylex(); 
 
} 

