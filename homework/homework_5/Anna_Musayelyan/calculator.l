%{
#include "calculator.tab.h"
void yyerror (char *s);
int yylex();
%}

%%
"print"				    { return print_token; }
"exit"				    { return exit_token; }
"sin"                   { return SIN; }
"cos"                   { return COS; }
"tan"                   { return TAN; }
"lg"                    { return LG; }
"ln"                    { return LN; }
"lg2"                   { return LG2; }
"log"                   { return LOG; }
[a-zA-Z]			    {
                            yylval.id = *yytext;
                            return identifier;
                        }
[0-9]+"."[0-9]+                  {
                            yylval.num = atof(yytext);
                            return fnumber;
                        }
[ \t\n]                ;
[-+*/%=;()]           	{ return *yytext; }
.                       { ECHO; yyerror ("unexpected character"); }


%%

int yywrap (void) {
    return 1;
}
