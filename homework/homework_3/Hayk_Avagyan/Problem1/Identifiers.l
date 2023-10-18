Letter [a-zA-Z_]
Digit [0-9]

%%
{Letter}({Letter}|{Digit})* printf("Identifier: %s \n", yytext);
.|\n    {}
%%