%%
if|else|while|for|int|double printf("keywords: %s \n", yytext);
.|\n    {}
%%

int yywrap(void){
    return 0;
}

int main()
{
    yylex();
}
