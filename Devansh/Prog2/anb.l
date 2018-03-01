%{
	#include <stdio.h>
	#include "yytab.h"
	extern yylval;
%}

%%
[A]	 { return 'A'; }
[B]	 { return 'B'; }
[\n] { return '\n'; }
%%

int yywrap() {
	return 1;
}
