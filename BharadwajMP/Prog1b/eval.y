%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token NUM
%left '+''-'
%left '*''/'

%%
S:exp {printf("%d\n",$$);}
exp:exp'+'exp {$$ = $1 + $3;}
   |exp'-'exp {$$ = $1 - $3;}
   |exp'*'exp {$$ = $1 * $3;}
   |exp'/'exp { if($3 == 0)
			yyerror("Divide by zero error!!");
		else
			$$ = $1 / $3;
	      }
   |'('exp')' {$$ = $2;}
   |NUM {$$ = $1;}
%%

void yyerror(char *msg)
{
	printf("Error : %s\n",msg);
	exit(-1);
}

void main()
{
	printf("Enter expression :");
	yyparse();
}
