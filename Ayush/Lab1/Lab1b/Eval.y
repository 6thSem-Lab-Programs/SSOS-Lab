%{
#include<stdio.h>
%}

%token NUM
%left '+''-'
%left '/''*'

%%
input : exp {printf("\nResult :\t%d\n",$$);exit(0);}
exp : exp'+'exp {$$=$1+$3;}
    | exp'-'exp {$$=$1-$3;}
    | exp'*'exp {$$=$1*$3;}
    | exp'/'exp {if($3==0)yyerror("Divide by zero Error !"); else $$=$1/$3;}
    | '('exp')' {$$=$2;}
    | NUM {$$=$1;}
%%

int main() {
	printf("\nEnter the Expression :\t");
	yyparse();
	return 0;
}

void yyerror(char *msg) {
	printf("\nError :\t%s\n",msg);
}
