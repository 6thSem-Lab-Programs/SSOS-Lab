%{
#include<stdio.h>
#include<stdlib.h>
int sc=0,mc=0;
%}

%%
"//".* {sc++;}
"/*"[a-zA-Z0-9 ' ' \n\t \- + *]+"*/" { mc++; }
%%
void main() {
	yyin=fopen("input.c","r");
	yyout=fopen("output.c","w");
	yylex();
	printf("no. of single line comment:%d \n",sc);
	printf("no. of multiline comment lines :%d\n",mc);
	fclose(yyin);
	fclose(yyout);	
}
int yywrap() {}	
