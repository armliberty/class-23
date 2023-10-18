identifier [a-zA-Z0-9_]

%%
{identifier}*  printf("Identifier: %s \n", yytext);
.|\n {}
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}
