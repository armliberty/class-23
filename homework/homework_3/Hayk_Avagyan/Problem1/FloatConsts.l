Digit [0-9]

%%
(\+|\-)?{Digit}+?((\.?e?\-?{Digit}+e\-?{Digit}+)|(\.{Digit}+?)) printf("Floating point constant: %s \n", yytext);
.|\n    {}
%%