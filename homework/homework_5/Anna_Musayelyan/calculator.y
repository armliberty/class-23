%{
void yyerror(char*);
int yylex();

#include <ctype.h> /* islower */
#include <stdlib.h> /* exit */
#include <stdio.h> /* printf */
#include <math.h>

int symbols[52];
void setSymbolValue(char symbol, double value);
double getSymbolValue(char symbol);

%}

%start program
%union {double num; char id; }
%token print_token exit_token SIN COS TAN LG LN LG2 LOG
%token <num> fnumber
%token <id> identifier
%type <num> expr term factor func
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
            | identifier '=' expr '.' expr
            ;

expr        : expr '+' term             { $$ = $1 + $3; }
            | expr '-' term             { $$ = $1 - $3; }
            | term                      { $$ = $1; }
            ;

term        : term '*' factor           { $$ = $1 * $3; }
            | term '/' factor           { $$ = $1 / $3; }
            | term '%'factor            { $$ = fmod($1, $3); } 
            | factor
            ;


factor      : '(' expr ')'              { $$ = $2; } 
            | fnumber                   { $$ = $1; }     
            | identifier                { $$ = getSymbolValue($1); }
            ;

func        : SIN '(' expr ')'          { $$ = sin($3); }
            | COS '(' expr ')'          { $$ = cos($3); }
            | TAN '(' expr ')'          { $$ = tan($3); }
            | LG '(' expr ')'           { $$ = log10($3); }
            | LN '(' expr ')'           { $$ = log($3); }
            | LG2 '(' expr ')'          { $$ = log2($3); }
            | LOG '(' expr ',' expr ')' { $$ = log($3) / log($5); }
            ;

print_stmt  : print_token identifier    { printf("%.2f\n", getSymbolValue($2)); }
            | print_token '(' expr ')'  { printf("%f\n", $3); }
            ;

exit_stmt   : exit_token                { exit(EXIT_SUCCESS); }
            ;

%%

int computeSymbolIndex(char symbol) {
    return islower(symbol) ? symbol - 'a' : symbol - 'A' + 26;
}

void setSymbolValue(char symbol, double value) {
    symbols[computeSymbolIndex(symbol)] = value;
}

double getSymbolValue(char symbol) {
    return symbols[computeSymbolIndex(symbol)];
}

int main(void) {
    return yyparse();
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
} 
