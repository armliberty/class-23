%%
\(  printf("Left parenthesis: %s \n", yytext);
\)  printf("Right parenthesis: %s \n", yytext);
\;  printf("Semicolon: %s \n", yytext);
\{  printf("Left curly brace: %s \n", yytext);
\}  printf("Right curly brace: %s \n", yytext);
.|\n    {}
%%

int yywrap(void){
    return 0;
}

int main()
{
    yylex();
}