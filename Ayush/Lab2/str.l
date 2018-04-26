%{
#include <stdio.h>
#include "y.tab.h"
extern yylval;
%}

%%
[A] { return 'A'; }
[B] { return 'B'; }
[\n] { return'\n'; }

%%
int yywrap() {
	return 1;
}
