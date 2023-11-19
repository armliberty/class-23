simbols [+-_]
letter  [b-zB-Z_0-9]

%%

(({letter}|{simbols})a?)*b+ {
            					printf("Identifier=%s ", yytext);
        					}

.|\n {}

%%

int main(void) {
	yylex();

}
