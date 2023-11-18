%{
#include "calculator_float.tab.h"
void yyerror (char *s);
int yylex();
%}

%%
"print"				    { return print_token; }
"exit"				    { return exit_token; }
[a-zA-Z]			    {
                            yylval.id = *yytext;
                            return identifier;
                        }
([0-9]+)([+-]?([0-9]*[.]?[0-9])*)                  {
                            yylval.num = atof(yytext);
                            return number;
                        }
SIN { return SIN; }
COS { return COS; }
TAN { return TAN; }
LG  { return LG;  }
LG2 { return LG2; }
LN  { return LN;  }
LOG { return LOG; }
MOD { return MOD; }
[ \t\n]                ;
[-+=;*/.()]           	    { return *yytext; }
.                       { ECHO; yyerror ("unexpected character"); }


%%

int yywrap (void) {
    return 1;
}