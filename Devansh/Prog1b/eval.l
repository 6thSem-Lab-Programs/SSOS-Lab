%{
	#include "y.tab.h"
	extern yylval;
%}

%%
[0-9]+ 			{ yylval = atoi(yytext); return NUM; }
[+|-|*|/] 	{ return yytext[0]; }
%%

int yywrap()
{
	return 1;
}
