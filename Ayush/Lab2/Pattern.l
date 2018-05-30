%{
#include<stdio.h>
#include "y.tab.h"
extern yylval;
%}

%%
[A|a] {return 'A';}
[B|b] {return 'B';}
[\n] {return '\n';}
%%

int yywrap() {
	return 1;
}
