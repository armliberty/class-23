digit [0-9]
letter [a-zA-Z_]

%{
#include <stdio.h>
%}

%{
int keywordsCount = 0;
int identifiersCount = 0;
int integersCount = 0;
int floatsCount = 0;
int operatorsCount = 0;
int delimitersCount = 0;
%}

%%
if|else|while|for|int|double                            {++keywordsCount;}
[a-zA-Z_][a-zA-Z_0-9]*                            {++identifiersCount;}
[-+]?[0-9]+                                         {++integersCount;}
[-+]?[0-9]*\.?[0-9]*([eE][-+]?[0-9]+)?      {++floatsCount;}
[+\-\*/%=<>]=|==|>=|<=                                  {++operatorsCount;}
[();{}]                                                 {++delimitersCount;}
%%

int main() {
    yylex();
    printf("Count of Keywords: %d\n", keywordsCount);
    printf("Count of Identifiers: %d\n", identifiersCount);
    printf("Count of Integers: %d\n", integersCount);
    printf("Count of Floats: %d\n", floatsCount);
    printf("Count of Operators: %d\n", operatorsCount);
    printf("Count of Delimiters: %d\n", delimitersCount);

    return 0;
}