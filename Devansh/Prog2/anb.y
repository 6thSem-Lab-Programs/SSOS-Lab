%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%%
input:S'\n' {
	printf("The string follows the grammer\n");
	exit(0);
}
S:'A'S
 |S1
S1:'B'S2
S2: ;
  |'B' {
  	printf("The string does not match the grammer\n");
	exit(1);
}
  |'A' {
  	printf("The string does not match the grammer\n");
	exit(1);
}
%%

int yyerror(char *msg) {
	printf("Error : %s\n", msg);
}

void main() {
	printf("Enter the string : ");
	yyparse();
}
