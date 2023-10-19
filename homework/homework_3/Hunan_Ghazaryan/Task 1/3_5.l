%%
\-  printf("minus sign: %s \n", yytext);      
\+  printf("pluse sign: %s \n", yytext);
\*  printf("multiplay sign: %s \n", yytext);
\/  printf("division sign: %s \n", yytext);
\%  printf("mod sign: %s \n", yytext);
\<= printf("small or equal sign: %s \n", yytext);
\>= printf("big or equal sign: %s \n", yytext);
\<  printf("small sign: %s \n", yytext);
\>  printf("big sign: %s \n", yytext);
\=  printf("assign sign: %s \n", yytext);
\== printf("equal sign: %s \n", yytext);
.|\n    {}
%%

int yywrap(void){
    return 0;
}

int main()
{
    yylex();
}