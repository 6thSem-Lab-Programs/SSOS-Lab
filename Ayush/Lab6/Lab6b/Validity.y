%{
#include<stdio.h>
int key=0,id=0,op=0,dig=0;
%}

%token ID DIGIT KEY OP

%%
input : DIGIT input {dig++;}
      | ID input {id++;}
      | KEY input {key++;}
      | OP input {op++;}
      | DIGIT {dig++;}
      | ID {id++;}
      | KEY {key++;}
      | OP {op++;}
%%
extern FILE *yyin;
int main() {
	FILE *fin = fopen("input.c","r");
	if(!fin){
		printf("\nError Opening File !\n");
		exit(1);
	}
	yyin = fin;
	do{
		yyparse();
	}while(!feof(yyin));
	printf("\nDigits :t%d\nKeywords :t%d\nIdentifiers :t%d\nOperators :t%d\n",dig,key,id,op);
	return 0;
}

void yyerror() {
	printf("\nError !\n");
	exit(1);
}
