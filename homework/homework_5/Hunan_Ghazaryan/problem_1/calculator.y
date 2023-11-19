%{
void yyerror(char*);
int yylex();

#include <ctype.h> /* islower */
#include <stdlib.h> /* exit */
#include <stdio.h> /* printf */
#include <math.h> /* sin, cos, log, ln, ... */
#include <string.h> /* strcmp(...) */

int symbols[52];
void setSymbolValue(char symbol, double value);
int getSymbolValue(char symbol);



%}

%start program
%union {int num; char id; double floatnum;}
%token print_token exit_token
%token <num> number
%token <id> identifier
%token <floatnum> float_number
%type <floatnum> expr term factor
%type <id> asmt
%token <floatnum> sin_token
%token <floatnum> cos_token
%token <floatnum> tan_token
%token <floatnum> lg_token
%token <floatnum> ln_token
%token <floatnum> lg2_token
%token <floatnum> log_token
%left '+' '-'
%left '*' '/'
%left '(' ')'
%right MINUS
%right PLUSE

%%

program     : stmt
            | program ';' stmt
            ;

stmt        : asmt
            | print_stmt
            | exit_stmt
            ;

asmt        : identifier '=' expr         { setSymbolValue($1, $3); }
            ;

expr        : expr '+' term                         { $$ = $1 + $3; }
            | expr '-' term                         { $$ = $1 - $3; }
            | term                                  { $$ = $1; }
            ;

term        : term '*' factor                       { $$ = $1 * $3;}
            | term '/' factor                       { 
                                                        if($3 != 0)
                                                            $$ = $1 / $3;
                                                        else
                                                            {
                                                                yyerror("There is a division by zero!\n");
                                                                YYABORT;
                                                            }
                                                    }
            | term '%' factor                       {
                                                        if($3 != 0)
                                                            $$ = fmodl($1,$3);
                                                        else
                                                            {
                                                                yyerror("There is a modulus by zero!\n");
                                                                YYABORT;
                                                            }
                                                    }
            | factor                                { $$ = $1; }
            ;

factor      : number                                { $$ = $1; }
            | identifier                            { $$ = getSymbolValue($1); }
            | float_number                          { $$ = $1; }
            | '(' expr ')'                          { $$ = $2; }
            | sin_token '(' expr ')'                { $$ = computeFunction("sin", $3); }
            | cos_token '(' expr ')'                { $$ = computeFunction("cos", $3); }
            | tan_token '(' expr ')'                { $$ = computeFunction("tan", $3); }
            | lg_token '(' expr ')'                 { $$ = computeFunction("log10", $3); }
            | ln_token '(' expr ')'                 { $$ = computeFunction("log", $3); }
            | lg2_token '(' expr ')'                { $$ = computeFunction("log2", $3); }
            | log_token '(' expr ',' expr ')'       { $$ = computeFunction("log",$3)/computeFunction("log",$5); }
            | '-' factor %prec MINUS                { $$ = -$2; }
            | '+' factor %prec PLUSE                { $$ = +$2; }
            ;
print_stmt  : print_token expr          { printf("%f\n", $2); }
            ;

exit_stmt   : exit_token                { exit(EXIT_SUCCESS); }
            ;

%%

int computeSymbolIndex(char symbol) {
    return islower(symbol) ? symbol - 'a' : (isupper(symbol) ? symbol - 'A' + 26 : -1);
}

void setSymbolValue(char symbol, double value) {
    symbols[computeSymbolIndex(symbol)] = value;
}

int getSymbolValue(char symbol) {
    return symbols[computeSymbolIndex(symbol)];
}

double computeFunction(char* function, double argument) {
    if (strcmp(function, "sin") == 0) {
        return sin(argument);
    } else if (strcmp(function, "cos") == 0) {
        return cos(argument);
    } else if (strcmp(function, "tan") == 0) {
        return tan(argument);
    } else if (strcmp(function, "log10") == 0) {
        return log10(argument);
    } else if (strcmp(function, "log") == 0) {
        return log(argument);
    } else if (strcmp(function, "log2") == 0) {
        return log2(argument);
    } else {
        yyerror("ERROR!");
        return 0.0;  
    }
}


int main(void) {
    return yyparse();
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
} 