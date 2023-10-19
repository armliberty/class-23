letter [a-zA-Z]
digit [0-9]
symbol [!#$%&'*+-/=?^_`{|}~]

%%

(({letter}|{digit})+|{symbol}?)+@({letter}|{digit})+\.{letter}{2,} {
    printf("email = %s\n", yytext);
}

.|\n {}
%%

int main(void) {
    yylex();
    return 0;
}

