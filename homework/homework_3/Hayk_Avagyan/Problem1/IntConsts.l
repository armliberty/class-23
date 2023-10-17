Digit [0-9]

%%
(\+|\-)?{Digit}+ printf("Integer constant: %s \n", yytext);
.|\n    {}
%%