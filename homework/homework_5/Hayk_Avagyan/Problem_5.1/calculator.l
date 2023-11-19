%{
#include "calculator_update.tab.h"
#include <math.h>
void yyerror(char *s);
int yylex();
%}

%%
"print"                 { return print_token; }
"exit"                  { return exit_token; }
[a-zA-Z]                {
                            yylval.id = *yytext;
                            return identifier;
                        }
[0-9]+                  {
                            yylval.num = atoi(yytext);
                            return number;
                        }
[ \t\n]                ;
[-+*/%=;]               { return *yytext; }
MOD                     { return MOD; }
"sin"                   { return SIN; }
"cos"                   { return COS; }
"tan"                   { return TAN; }
"log"                   { return LOG; }
"ln"                    { return LN; }

[-+]?[0-9]*[.]?[0-9]+  {
                            yylval.num = atof(yytext);
                            return floatnum;
                        }

.                       { ECHO; yyerror("unexpected character"); }

%%

int yywrap(void) {
    return 1;
}
