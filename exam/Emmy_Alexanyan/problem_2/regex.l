%{
#include <stdio.h>
%}

%%
^a{0,1}[b-zB-Z0-9]*b+$  printf("identifier = %s\n",yytext);
.|\n {}



%%

int main(){

        printf("input text:");
        yylex();

}
