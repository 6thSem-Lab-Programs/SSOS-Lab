%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
input : S'\n' {printf("\nValid Pattern !!\n");exit(0);}
S  : 'A'S|S1
S1 : 'B'S2
S2 : ;
   | 'A' {printf("\nInvalid Pattern !!\n");exit(0);} 
   | 'B' {printf("\nInvalid Pattern !!\n");exit(0);} 
%%

int main() {
	printf("\nEnter the Pattern :\t");
	yyparse();
	return 0;
}

void yyerror() {
	printf("\nError\n");
	exit(1);
}
