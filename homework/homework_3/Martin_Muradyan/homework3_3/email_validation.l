%{
%}

%%
([A-Za-z0-9]+[!#$%&'*+-/=?^_`{|}~]?)+@[A-Za-z0-9]+\.[A-Za-z]{2,}       {printf("email = %s ", yytext);}

.|\n {}
%%

int main(void) {
    yylex();
    return 0;
}