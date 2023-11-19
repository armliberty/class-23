%{ 
#include "problem_1_int.tab.h" 
void yyerror (char *s); 
int yylex(); 
%}
%% 
"print"                           {  return print_token; } 
"exit"                            {  return exit_token; } 
[a-zA-Z]                          {  yylval.id = *yytext; 
                                     return identifier; 
                                  } 
[0-9]+                            { 
                                    yylval.num = atoi(yytext); 
                                    return number; 
                                  } 
[ \t\n]                           ; 
[-+*/=;(),]                       {  return *yytext; } 
MOD                               {  return MOD; } 
.                                 {  ECHO; yyerror ("unexpected character"); } 
 
 
%% 
 
int yywrap (void) { 
    return 1; 
}