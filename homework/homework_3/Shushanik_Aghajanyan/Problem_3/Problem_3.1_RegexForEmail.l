%%
[a-zA-Z0-9]+([-._]?[a-zA-Z0-9]+)*[@][a-zA-Z0-9]+([-._]?[a-zA-Z0-9]+)*[.][a-zA-Z]{2,} printf("Valid E-mail: %s \n", yytext);
.|\n    {}
%%


int main(void) {
	yylex();
}