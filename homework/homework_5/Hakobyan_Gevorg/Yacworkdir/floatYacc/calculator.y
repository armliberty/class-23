%{
void yyerror(char*);
int yylex();

#include <ctype.h> /* islower */
#include <stdlib.h> /* exit */
#include <stdio.h> /* printf */

double symbols[52];
void setSymbolValue(char symbol, double value);
double getSymbolValue(char symbol);

%}

%start program
%union {int num; char id; float floatNum;}
%token print_token exit_token
%token <num> number
%token <id> identifier
%token <floatNum> floatNumber
%type <floatNum> expr term
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

term        : number                    { $$ = $1; }
            | identifier                { $$ = getSymbolValue($1); }
            | floatNumber                {$$ = $1;}
            ;

print_stmt  : print_token expr          { printf("%.5f\n", $2); }
            ;

exit_stmt   : exit_token                { exit(EXIT_SUCCESS); }
            ;

%%

int computeSymbolIndex(char symbol) {
    return islower(symbol) ? symbol - 'a' : symbol - 'A' + 26;
}

//For double
void setSymbolValue(char symbol, double value) {
    symbols[computeSymbolIndex(symbol)] = value;
}
//for double 
double getSymbolValue(char symbol) {
    return symbols[computeSymbolIndex(symbol)];
}


int main(void) {
    return yyparse();
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
} 
