%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token num
%left '+' '-'
%left '*' '/'

%%
input:exp{printf("%d\n",$$); exit(0);}
exp:exp'+'exp{$$=$1+$3;}
|exp'-'exp{$$=$1-$3;}
|exp'*'exp{$$=$3*$1;}
|exp'/'exp{if($3==0) {printf("\nDivide by zero error !");exit(0); }
	   else $$=$1/$3;
	  }
|'('exp')'{$$=$2;}
|num{$$=$1;}
%%

void yyerror() {
	printf("Error !");
	exit(0);
}
int main() {
	printf("\nEnter an Expression :\n");
	yyparse();
	return 0;
}
