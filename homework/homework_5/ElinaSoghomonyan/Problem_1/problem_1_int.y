%{ 
void yyerror(char*); 
int yylex(); 
#include <ctype.h> /* islower */ 
#include <stdlib.h> /* exit */ 
#include <stdio.h> /* printf */ 
#include <math.h>  /* MOD */ 
 
int symbols[52]; 
void setSymbolValue(char symbol, int value); 
int getSymbolValue(char symbol); 
 
%} 
 
%start program 
%union {int num; char id; } 
%token print_token exit_token 
%token MOD 
%token <num> number 
%token <id> identifier 
%type  <num> expr term factor
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
 
expr        : expr '+' expr             { $$ = $1 + $3; } 
            | expr '-' expr             { $$ = $1 - $3; } 
            | term                      { $$ = $1; } 
            ; 
term        : term '*' factor           { $$ = $1 * $3; } 
            | term '/' factor           { $$ = $1 / $3; } 
            | term MOD factor           { $$ = fmod($1 , $3); } 
            | factor                    { $$ = $1; } 
            ;           
factor      : number                    { $$ = $1; } 
            | identifier                { $$ = getSymbolValue($1); } 
            |'('expr')'                 { $$ = $2; } 
            ; 
 
print_stmt  : print_token expr          { printf("%d\n", $2); } 
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