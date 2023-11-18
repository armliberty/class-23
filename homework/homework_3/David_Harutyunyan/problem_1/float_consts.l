digits [0-9]

%%
(\+|\-)?{digits}+?((\.?e?\-?{digits}+e\-?{digits}+)|(\.{digits}+?)) printf("Floating point constant: %s \n", yytext);
.|\n    {}
%%