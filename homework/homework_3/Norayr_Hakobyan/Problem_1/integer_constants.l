digits [0-9]

%%
(\+|\-)?{digits}+ printf("Integer constant: %s \n", yytext);
.|\n    {}
%%

int yywrap(void){
    return 0;
}

int main()
{
    yylex();
}