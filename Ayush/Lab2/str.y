%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
input:s'\n' {
	printf("the grammar is valid\n\n");
	exit(0);
}
s:'A' s|s1
s1:'B' s2
s2:;
  |'B' {
	printf("the string does not match the grammar\n\n");
	exit(1);
	}
  |'A'{ 
	printf("the string does not match the grammar\n\n");
	exit(1);
	}

%%
int yyerror(char *msg){
	printf("error encountered:\n %s\n\n",msg);
	exit(1);
}

int main(){
	printf("enter the string:\n");
	yyparse();
	return 0;
}
