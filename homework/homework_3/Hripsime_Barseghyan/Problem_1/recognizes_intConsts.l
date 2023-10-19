digits [0-9]

%%
(\+|\-)?{digits}+ printf("Integer constant: %s \n", yytext);
.|\n    {}
%%