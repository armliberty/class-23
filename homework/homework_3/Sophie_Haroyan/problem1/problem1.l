%{
#include <stdio.h>
%}

%{
enum TokenType { KEYWORD, IDENTIFIER, INTEGER, FLOAT, OPERATOR, DELIMITER, ERROR };
int counts[7] = {0};
%}

%%
if|else|while|for|int|double  {++counts[KEYWORD];}
[a-zA-Z_][a-zA-Z_0-9]*  {++counts[IDENTIFIER];}
[-+]?[0-9]+  {++counts[INTEGER];}
[-+]?[0-9]*\.?[0-9]*([eE][-+]?[0-9]+)?  {++counts[FLOAT];}
[+\-\*/%=<>]=|==|>=|<=  {++counts[OPERATOR];}
[();{}]  {++counts[DELIMITER];}
.  {++counts[ERROR];}
%%

int main() {
    yylex();
    printf("Count of Keywords: %d\n", counts[KEYWORD]);
    printf("Count of Identifiers: %d\n", counts[IDENTIFIER]);
    printf("Count of Integers: %d\n", counts[INTEGER]);
    printf("Count of Floats: %d\n", counts[FLOAT]);
    printf("Count of Operators: %d\n", counts[OPERATOR]);
    printf("Count of Delimiters: %d\n", counts[DELIMITER]);
    printf("Count of Errors: %d\n", counts[ERROR]);

    return 0;
}

