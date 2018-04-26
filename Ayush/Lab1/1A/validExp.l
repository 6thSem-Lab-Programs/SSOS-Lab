%{
#include<stdio.h>
int valid=0;
int m=0, a=0;
%}

%%
[+]			{a++;}
[*]			{m++;}
[0-9]			{printf("\nOperand : %s",yytext);valid=1;}
[[0-9]*[+|*][0-9]*]	{valid=1;}
[+|*][+|*]		{valid=0;}
%%

int yywrap() {
	return 1;
}

main() {
	yylex();
	if(valid==0)
		printf("\nInvalid Expression !!");
	printf("\nOperators\n");
	if(a!=0) printf("\n+ : %d\n",a);
	if(m!=0) printf("\n* : %d\n",m);
}
