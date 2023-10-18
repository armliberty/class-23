%{ 
#include <stdio.h> 
%} 
 
%% 
if | 
else | 
while | 
for | 
double | 
int {printf("keyword = %s\n", yytext);}  
.|\n {} 
 
 
 
%% 
 
int main(){ 
 
        printf("input text:"); 
        yylex(); 
 
} 
 
