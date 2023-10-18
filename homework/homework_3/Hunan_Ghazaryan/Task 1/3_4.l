digit [0-9]

%%
(\-|\+)?{digit}((\.?e?\-?{digit}+e\-?{digit}+)|(\.{digit}+?))   printf("floating point constants: %s \n", yytext);
.|\n    {}
%% 

int yywrap(void){
    return 0;
}

int main()
{
    yylex();
}