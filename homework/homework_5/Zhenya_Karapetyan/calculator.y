%{
void yyerror(char*);
int yylex();

#include <ctype.h> /* islower */
#include <stdlib.h> /* exit */
#include <stdio.h> /* printf */
#include <math.h>

int symbols[52];
void setSymbolValue(char symbol, int value);
int getSymbolValue(char symbol);

%}

%start program
%union {int num; char id; double fnum;}
%token print_token exit_token mod_token
%token <num> number
%token <id> identifier
%token <fnum> floatnum SIN COS TAN LG LN LG2 LOG
%type <fnum> expr term factor
%type <id> asmt

%%

program     : stmt
            | program ';' stmt
            ;

stmt        : asmt
            | print_stmt
            | exit_stmt
            ;

asmt        : identifier '=' expr               { setSymbolValue($1, $3); }
            ;

expr        : expr '+' term             { $$ = $1 + $3; }
            | expr '-' term             { $$ = $1 - $3; }
            | term                      { $$ = $1; }
            ;

term        : term '*' factor          { $$ = $1 * $3; }
            | term '/' factor          { ($3 != 0) ? $$ = $1 / $3 : yyerror("Division by zero"); }
            | term mod_token factor    { $$ = fmod($1, $3); }
            | factor                   { $$ = $1; }
            ;

factor      : number                      { $$ = $1; }
            | identifier                  { $$ = getSymbolValue($1); }
            | floatnum                    { $$ = $1; }
            | SIN '(' expr ')'            { $$ = sin($3); }
            | COS '(' expr ')'            { $$ = cos($3); }
            | TAN '(' expr ')'            { $$ = tan($3); }
            | LG '(' expr ')'             { $$ = log10($3); }
            | LN '(' expr ')'             { $$ = log($3); }
            | LG2 '(' expr ')'            { $$ = log2($3); }
            | LOG '(' expr ',' expr ')'   { $$ = log($3) / log($5); }
            | '(' expr ')'                { $$ = $2; }
            ;

print_stmt  : print_token expr          { printf("%f\n", $2); }
            ;

exit_stmt   : exit_token                { exit(EXIT_SUCCESS); }
            ;

%%

int computeSymbolIndex(char symbol) {
    return islower(symbol) ? symbol - 'a' : symbol - 'A' + 26;
}

void setSymbolValue(char symbol, int value) {
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