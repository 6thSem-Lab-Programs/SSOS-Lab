%{
#include<stdio.h>
#include<math.h>
#include "y.tab.h"
extern yylval;
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUM;}
[+|/|*|(|)] {return yytext[0];}
[-] {return '-';}
\n {return 0;}
.	{;}
%%

int yywrap() {
	return 1;
}
