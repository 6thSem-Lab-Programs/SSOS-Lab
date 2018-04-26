%{
#include<stdio.h>
#include<stdlib.h>
int id=0,digit=0,key=0,op=0;
%}

%token KEY ID OP DIGIT
%%
input:DIGIT input {digit++;} 
|ID input {id++;}
|OP input {op++;}
|KEY input {key++;}
|DIGIT {digit++;} 
|ID {id++;}
|OP {op++;}
|KEY {key++;}
%%

extern int yylex();
extern int yyparse();
extern FILE *yyin;

int yyerror(char *msg){
	printf("error encountered:\n %s\n\n",msg);
	exit(1);
}

int main(){
	FILE *myfile = fopen("input.c","r");
	if(!myfile) {
		printf("\nCan't Open File !\n");
		return -1;
	}
	yyin = myfile;
	do {
		yyparse();
	}while(!feof(yyin));
	printf("\nNumber = %d\nKeywords = %d\nOperands = %d\nIdentifiers = %d\n",digit,key,op,id);
	return 0;
}
