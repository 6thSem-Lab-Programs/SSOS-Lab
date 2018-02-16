%{
	#include "y.tab.h"
	extern yylval;
%}

%%
[0-9]+ {
		yylval = atoi(yytext);
		return NUM;	
       }

[+]  return '+';
[-] return '-';
[*] return '*';
[/] return '/';
[\n] return 0;
["("|")"] return yytext[0];
. return yytext[0];
%%

int yywrap()
{
	return 1;
}
