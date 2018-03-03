%{
	#include <stdio.h>
	#include <stdlib.h>

	int q, slc, mlc;
%}

%%
["]		{ q = !q; wtf(); }

"//"	{ if(q == 0) { slc = 1; } }

"/*"	{ if(q == 0) { mlc = 1; } }

"*/"	{ if(mlc == 1) { mlc = 0; } }

"\n"	{ if(slc == 1) { slc = 0; } wtf(); }

.		{ if(slc == 0 && mlc == 0) { wtf(); } }
%%

int yywrap() {
	return 1;
}

// Write to File XD
void wtf() {
	fprintf(yyout, "%c", yytext[0]);
}

void main() {
	yyin = fopen("in.c", "r");
	yyout = fopen("out.c", "w");

	yylex();
}
