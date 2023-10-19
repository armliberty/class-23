letters [a-zA-Z]
digits [0-9]
symbols [\.\-]

%%
({letters}|{digits}){symbols}*({letters}|{digits})*\@({letters}|{digits}|\-)+\.{letters}+  printf("Email is valid:%s\n", yytext);

.|\n {}
%%
