%{ 
void yyerror(char*); 
int yylex(); 
 
#include <ctype.h> /* islower */ 
#include <math.h> 
#include <stdlib.h> /* exit */ 
#include <stdio.h> /* printf */ 
 
int symbols[52]; 
void setSymbolValue(char symbol, float value); 
float getSymbolValue(char symbol); 
 
%} 
 
%start program 
%union {float num; char id; } 
%token print_token exit_token 
%token SIN COS TAN LG LG2 LN LOG MOD 
%token <num> number 
%token <id> identifier 
%type <num> expr term factor  
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
            | SIN '('expr')'            { $$ = sin($3); } 
            | COS '('expr')'            { $$ = cos($3); }                
            | TAN '('expr')'            { $$ = tan($3); } 
            | LG  '('expr')'            { $$ = log10($3); } 
            | LN  '('expr')'            { $$ = log($3); } 
            | LG2 '('expr')'            { $$ = log($3)/log(2);} 
            | LOG '('expr ','expr')'    { $$ = log($3)/log($5);   } 
            | term                      { $$ = $1; } 
            ; 
 
term        : term '*' factor           { $$ = $1 * $3; } 
            | term '/' factor           { $$ = $1 / $3; } 
            | term MOD factor           { $$ = fmod($1,$3); } 
            | factor                    { $$ = $1; } 
            ; 
             
factor      : number                    { $$ = $1; } 
            | identifier                { $$ = getSymbolValue($1); } 
            | '('expr')'                { $$ = $2; } 
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
 
float getSymbolValue(char symbol) { 
    return symbols[computeSymbolIndex(symbol)]; 
} 
 
int main(void) { 
    return yyparse(); 
} 
 
void yyerror(char *s) { 
    fprintf(stderr, "%s\n", s); 
}