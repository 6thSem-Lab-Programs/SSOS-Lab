%{
#include<stdio.h>
#include<stdlib.h>
%}
%token num
%left '+''-'
%left '*''/'
%%
input:exp	{printf("\nResult :\t%d\n",$$);}
exp:exp'+'exp	{$$=$1+$3;}
   |exp'-'exp	{$$=$1-$3;}
   |exp'*'exp	{$$=$1*$3;}
   |exp'/'exp	{if($3==0){printf("\nDivide by zero error !\n");exit(1);} else $$=$1/$3;}
   |'('exp')'	{$$=$2;}
   |num		{$$=$1;}
%%
int main() {
	printf("\nEnter an Expression :\t");
	yyparse();
	return 0;
}

void yyerror(char *msg) {
	printf("Error \t%s",msg);
	exit(1);
}
