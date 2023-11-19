%{
#include "y.tab.h"
#include <math.h>
void yyerror (char *s);
int yylex();
%}

digits [0-9]

%%
"print"				    { return print_token; }
"exit"				    { return exit_token; }


[a-zA-Z]			    {
                            yylval.id = *yytext;
                            return identifier;
                        }
[0-9]+                  {
                            yylval.num = atoi(yytext);
                            return number;
                        }

(\+|\-)?{digits}+?((\.?e?\-?{digits}+e\-?{digits}+)|(\.{digits}+?))          {
                                                                                yylval.floatnum = atof(yytext);
                                                                                return float_number;
                                                                             }



[ \t\n]                 ;
[-+=*/()%;]           	{ return *yytext; }

sin                     {return sin_token;}
cos                     {return cos_token;}
tan                     {return tan_token;}

.                       { ECHO; yyerror ("unexpected character"); }


%%

int yywrap (void) {
    return 1;
}