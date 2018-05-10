%{
#include<stdio.h>
#include<math.h>
#include "y.tab.h"
extern yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext); return num;}
[+|/|*|(|)]	{return yytext[0];}
[-]	{return '-';}
[.]	{;}
\t+	{;}
\n 	{return 0;}
%%

int yywrap() {
	return 1;
}
