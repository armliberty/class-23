digit      [0-9]
letter     [a-zA-Z_]
keyword    if|else|while|for|int|double
sign       [+-]
dot        \.
operators  ("=="|">="|"<="|[-+*/%=<>])
delimiters [();{}]
%{
int count = 0;
%}

%%
{keyword} {
            					printf("Keyword = %s \n", yytext);
                				++count;
        					}
{sign}?{digit}+ {
            					printf("Integer = %s \n", yytext);
                				++count;
        					}
{sign}?((({digit}+{dot}{digit}*)|({digit}*{dot}{digit}+))|({sign}?{digit}+))([e]{sign}?{digit}+)? {
            					printf("Float = %s \n", yytext);
                				++count;
        					}
  
{operators} {
            					printf("Operators = %s \n", yytext);
                				++count;
        					}
{delimiters} {
            					printf("Delimiter = %s \n", yytext);
                				++count;
        					}        					
        					
.|\n {}

%%

int main(void) {
	yylex();
	printf("Identifier count: %d\n", count);
}
