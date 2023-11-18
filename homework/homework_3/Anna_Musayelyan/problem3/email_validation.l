%{
#include <stdio.h>
%}



%%
[A-Za-z0-9._-]+{5,31}@[A-Za-z0-9.-]+\.[A-Za-z]{2,3} { printf("Valid E-mail: %s \n", yytext);}
.|\n  {}
%%


int main() {
	
	yylex();
   	return 0;
}

