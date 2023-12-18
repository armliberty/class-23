allwithoutaA [b-zB-Z0-9]
%%

([a]{1}{allwithoutaA}+[a]{1})*[b]+
                            printf("isValid:%s ", yytext);   
                            
.|\n {}

%%


int main(void) {
	yylex();
}