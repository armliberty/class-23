
digit [0-9]
letter [a-zA-Z_]

%%
{letter}({letter}|{digit})* printf("Identifier: %s \n", yytext);
.|\n    {}
%%

//int yywrap(void){
//    return 0;
//}
//
//int main()
//{
//    yylex();
//}