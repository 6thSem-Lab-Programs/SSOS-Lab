%{
	#include<stdio.h>
%}

%%
"//"[^\n]*[\n] {}
[/*][^\n]*[*/] {}
["][^"]*[/*][^*/]*[*/][^*/]*["] {fprintf(yyout,"%s",yytext);}
. {fprintf(yyout,"%s",yytext);}
%%

int yywrap()
{
	return 1;
}

void main()
{
	yyin = fopen("in.c","r");
	yyout = fopen("out.c","w");
	yylex();
}
