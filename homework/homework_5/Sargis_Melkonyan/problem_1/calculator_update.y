%{
void yyerror(char*);
int yylex();

#include <ctype.h> /* islower */
#include <stdbool.h> /* sizeof */
#include <stdlib.h> /* exit */
#include <stdio.h> /* printf */
#include <math.h> /* fmod */
int symbols[52];
void setSymbolValue(char symbol, int value);
int getSymbolValue(char symbol);
double getDoubleValue(int number);
int getIntegerValue(double number);

%}

%start program
%union {int num; char id; double fnum; }
%token print_token exit_token 
%token MOD
%token <fnum> floatnum
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

asmt        : identifier '=' expr     { setSymbolValue($1, $3); }
            ;
            

expr        : expr '+' term             { $$ = $1 + $3; }
            | expr '-' term             { $$ = $1 - $3; }
            | expr '*' term             { $$ = $1 * $3; }    
            | expr '/' term             { $$ = $1 / $3; }   
            | expr MOD term             { $$ = fmod($1,$3); }   //error */
            | term                      { $$ = $1; }
            ;

term        : term '*' factor           { $$ = $1 * $3; }
            | term '/' factor           { $$ = $1 / $3; }
            | term '%' factor           { $$ = $1 % $3; }  
            | factor                    { $$ = $1; } 
            ;

factor      : number                    { $$ = getIntegerValue($1); }
            | floatnum                  { $$ = getDoubleValue($1); }
            | identifier                { $$ = $1; }
            ;

print_stmt  : print_token expr          { 
                                          if(sizeof($2) == sizeof(int)){
                                            printf("%d\n", (int)$2);
                                          }
                                          else
                                            printf("%f\n", (double)$2);
                                        }
            /* | print_token expr          { printf("%d\n", $2); } */
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

double getDoubleValue(int number){
    double fnumber = number;   
    return fnumber;
}

int getIntegerValue(double number){
    int inumber = number;
    return inumber;
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
