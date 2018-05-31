%{
#include<stdio.h>
int slc=0,mlc=0;
%}

%%
"//".* {slc++;}
"/*"[a-zA-Z0-9' '\t\n\-+*/]+"*/" {mlc++;}
%%

int main() {
	yyin = fopen("input.c","r");
	yyout = fopen("output.c","w");
	yylex();
	printf("\nNumber of Single Line comments :\t%d",slc);
	printf("\nNumber of Multi  Line comments :\t%d\n\n",mlc);
	fclose(yyin);
	fclose(yyout);
	return 0;
}

int yywrap() {
	return 1;
}
