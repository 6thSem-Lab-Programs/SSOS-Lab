%{
	#include <stdio.h>
	int cc, wc, lc;
%}

%%
[a-z|A-Z|0-9]	{ cc++; }
" "				{ wc++; }
"\n"			{ lc++; }
%%

int yywrap() {
	return 1;
}

int main() {
	cc = 0;
	wc = 0;
	lc = 0;

	printf("Enter the text\n");

	yylex();

	printf("No. of chars : %d\nNo. of words : %d\nNo. of lines : %d\n", cc, wc, lc);
}
