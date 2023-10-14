digit [0-9]
letter [a-zA-Z]
sign [+|-]
dot [.]
delimiters [(|)|{|}]
operators [+|-|*|%|/|>=|<=|==|>|<]

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%{
#define MAX_KEYWORD 50
char keywords[MAX_KEYWORD][32];
int keywordCount = 0;
#define MAX_IDENTIFIER 50
char identifiers[MAX_IDENTIFIER][50];
int identifierCount = 0;
#define MAX_INTEGER 50
char integers[MAX_INTEGER][20];
int integerCount = 0;
#define MAX_FLOATING 50
char floatings[MAX_FLOATING][50];
int floatingCount = 0;
#define MAX_OPERATOR 50
char operators[MAX_OPERATOR][50];
int operatorCount = 0;
#define MAX_DELIMITER 50
char delimiters[MAX_FLOATING][50];
int delimiterCount = 0;

void storeKeyword(const char* keyword) {
    if (keywordCount < MAX_KEYWORD) {
        strcpy(keywords[keywordCount], keyword);
        keywordCount++;
    }
}

void storeIdentifier(const char* identifier) {
    if (identifierCount < MAX_IDENTIFIER) {
        strcpy(identifiers[identifierCount], identifier);
        identifierCount++;
    }
}

void storeIntegers(const char* integer) {
    if (integerCount < MAX_INTEGER) {
        strcpy(integers[integerCount], integer);
        integerCount++;
    }
}
void storeFloatings(const char* floating) {
    if (floatingCount < MAX_FLOATING) {
        strcpy(floatings[floatingCount], floating);
        floatingCount++;
    }
}
void storeOperators(const char* operatore) {
    if (operatorCount < MAX_OPERATOR) {
        strcpy(operators[operatorCount], operatore);
        operatorCount++;
    }
}
void storeDelimiters(const char* delimiter) {
    if (delimiterCount < MAX_DELIMITER ) {
        strcpy(delimiters[delimiterCount], delimiter);
        delimiterCount++;
    }
}



void printKeywords() {
    if (keywordCount) {
        printf("Keywords: ");
        for (int i = 0; i < keywordCount; ++i) {
            printf("%s", keywords[i]);
            printf(",");
        }
        printf("\n");
    } else {
        printf("No keywords found!\n");
    }
}
void printIdentifiers() {
    if (identifierCount) {
        printf("Identifiers: ");
        for (int i = 0; i < identifierCount; ++i) {
            printf("%s", identifiers[i]);
            printf(", ");
        }
        printf("\n");
    } else {
        printf("No identifiers found!");
        printf("\n");
    }
}

void printIntegers() {
    if (integerCount) {
        printf("Integers: ");
        for (int i = 0; i < integerCount; ++i) {
            printf("%s", integers[i]);
            printf(", ");
        }
        printf("\n");
    } else {
        printf("No integers found!");
        printf("\n");
    }
}
void printFloatings() {
    if (floatingCount) {
        printf("Floatings: ");
        for (int i = 0; i < floatingCount; ++i) {
            printf("%s", floatings[i]);
            printf(", ");
        }
        printf("\n");
    } else {
        printf("No floatings found!");
        printf("\n");
    }
}
void printDelimiters() {
    if (delimiterCount) {
        printf("Delimiters: ");
        for (int i = 0; i < delimiterCount; ++i) {
            printf("%s", delimiters[i]);
            printf(", ");
        }
        printf("\n");
    } else {
        printf("No delimiters found!");
        printf("\n");
    }
}
void printOperators() {
    if (operatorCount) {
        printf("Operators: ");
        for (int i = 0; i < operatorCount; ++i) {
            printf("%s", operators[i]);
            printf(", ");
        }
        printf("\n");
    } else {
        printf("No operators found!");
        printf("\n");
    }
}
%}


%%
{letter}{2,}  { storeKeyword(yytext); ++keywordCount; }
{letter}+{digit}*|({digit}+{letter}+) { storeIdentifier(yytext); ++identifierCount;} 
{sign}?{digit}+ { storeIntegers(yytext); ++integerCount; }
{sign}?{digit}+{dot}{digit}*|{digit}*{dot}{digit}+ { storeFloatings(yytext),++floatingCount;}
{operators}+ { storeOperators(yytext); ++operatorCount; }
{delimiters}+ { storeDelimiters(yytext); ++delimiterCount; }
.|\n|\t {}                        
%%

int main() {
    yylex();
    printKeywords();
    printIdentifiers();
    printIntegers();
    printFloatings();
    printDelimiters();
    printOperators();
    return 0;
}

