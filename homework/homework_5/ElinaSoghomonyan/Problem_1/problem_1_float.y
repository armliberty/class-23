%{
void yyerror(char*);
int yylex();

#include <ctype.h> /* islower */
#include <stdlib.h> /* exit */
#include <stdio.h> /* printf */
#include <math.h>  /*sin() cos() tan() log() */

int symbols[52];
void setSymbolValue(char symbol, float value);
int getSymbolValue(char symbol);

%}

%start program
%union {float num; char id; }
%token print_token exit_token
%token SIN COS TAN LG LN LOG LG2
%token <num> number
%token <id> identifier
%type  <num> expr  term
%type <id> asmt

%%

program     : stmt
            | program ';' stmt
            ;

stmt        : asmt
            | print_stmt
            | exit_stmt
            ;

asmt        : identifier '=' expr       { setSymbolValue($1, $3); }
            ;

expr        : expr '+' term             { $$ = $1 + $3; }
            | expr '-' term             { $$ = $1 - $3; }
            | expr '*' term             { $$ = $1 * $3; }
            | expr '/' term             { $$ = $1 / $3; }
            | SIN  '('expr')'           { $$ = sin($3); }
            | COS  '('expr')'           { $$ = cos($3); }
            | TAN  '('expr')'           { $$ = tan($3); }
            | LN   '('expr')'           { $$ = log($3); }
            | LG   '('expr')'           { $$ = log10($3);         }
            | LG2  '('expr')'           { $$ = log($3)/log(2);    }
            | LOG  '('expr ','expr')'   { $$ = log($5)/log($3);   }
            | term                      { $$ = $1; }
            ;

term        : number                    { $$ = $1; }
            | identifier                { $$ = getSymbolValue($1); }
            ;

print_stmt  : print_token expr          { printf("%f\n", $2); }
            ;

exit_stmt   : exit_token                { exit(EXIT_SUCCESS); }
            ;

%%

int computeSymbolIndex(char symbol) {
    return islower(symbol) ? symbol - 'a' : symbol - 'A' + 26;
}

void setSymbolValue(char symbol, float value) {
    symbols[computeSymbolIndex(symbol)] = value;
}

int getSymbolValue(char symbol) {
    return symbols[computeSymbolIndex(symbol)];
}

int main(void) {
    return yyparse();
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
} 
