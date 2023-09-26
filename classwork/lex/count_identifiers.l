digit	[0-9]
letter  [a-zA-Z_]

%{
int count = 0;
%}

%%

{letter}({letter}|{digit})*	{
					printf("Identifier=%s", yytext);
					++count;
				}

.* {}

%%

int main(void) {
	yylex();
	printf("Found %d identifiers.\n", count);
	return 0;
}

