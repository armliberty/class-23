digit    [0-9]
letter  [a-zA-Z_]

%{
int count = 0;
%}

%%

{letter}({letter}|{digit})* {
            					printf("Identifier=%s ", yytext);
                				++count;
        					}

.|\n {}

%%

int main(void) {
	yylex();
	printf("Identifier count: %d\n", count);
}
