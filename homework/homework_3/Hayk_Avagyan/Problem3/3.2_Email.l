digits [0-9]
letters [a-zA-Z]
symbols [._-]

%%
{letters}({letters}|{digits}|{symbols})*@({letters}|-)+\.{letters}*  printf("Valid E-mail: %s \n", yytext);
.|\n    {}
%%