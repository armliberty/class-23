letters [a-zA-Z_]
digits [0-9]

%%
{letters}({letters}|{digits})* printf("Identifier: %s \n", yytext);
.|\n    {}
%%