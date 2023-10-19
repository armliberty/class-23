digit [0-9]
letter [a-zA-Z_]

%%
if|else|while|for|int|double   {
            printf("keywords:%s ", yytext);  
            }
{letter}({letter}|digit)*   {
                            printf("identifier:%s ", yytext);   
                            }
[+-]?[0-9]+ {
            printf("constant:%s ", yytext); 
            } 
"+"|"-"|"*"|"/"|"%"|"="|"=="|"<"|">"|">="|"<="|"."  {
                                                    printf("operators:%s ", yytext); 
                                                    }
[+-]?({digit}*[.]?{digit}*([e][+-]?{digit}+)?)  {
                                                printf("floats:%s ", yytext);
                                                }
[(){};] {
        printf("delimeters:%s ", yytext);
        }

.|\n {}

%%

int main(void) {
	yylex();
}