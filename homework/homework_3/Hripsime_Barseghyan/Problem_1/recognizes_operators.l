%%
\+  printf("Plus sign: %s \n", yytext);
\-  printf("Minus sign: %s \n", yytext);
\*  printf("Asterisk: %s \n", yytext);
\/  printf("Slash: %s \n", yytext);
\%  printf("Percent sign: %s \n", yytext);
\=  printf("Equals sign: %s \n", yytext);
\== printf("Equals sign x2: %s \n", yytext);
\<  printf("Smaller than sign: %s \n", yytext);
\>  printf("Greater than sign: %s \n", yytext);
\>= printf("Greater than or equals to sign: %s \n", yytext);
\<= printf("Smaller than or equals to sign: %s \n", yytext);
.|\n    {}
%%