%{
#include<stdio.h>
#include<string.h>
int plus=0, mul=0, op=0, bracket=0,exOperator=0,exOperand=0,exBracket=0,i=0,j=0,invalid=0;
char **operand, **operator;
%}
%%
[0-9]+	{strcpy(operand[i++],yytext); op++; exOperand=0; exOperator=1; if(bracket>0)exBracket++;}
[(]	{bracket++;}
[)]	{if(exBracket>=1){bracket--;exBracket--;}else invalid=1;}
[+|*]	{strcpy(operator[j++],yytext); 
	 if(exOperator==1) {
		if(yytext=="+") plus++; 
		else mul++;
		exOperator=0;exOperand=1;
	 }else if (exOperator==0) invalid=1; 
	 else if(exOperand==1) invalid=1;
	}
.	{invalid=1;}
%%

int yywrap() {
	return 1;
}

void main() {
	int k;
	operand = (char**)malloc(sizeof(char*)*10);
	operator = (char**)malloc(sizeof(char*)*10);
	for(k=0;k<10;++k) {
		operand[k] = (char*)malloc(sizeof(char)*10);
		operator[k] = (char*)malloc(sizeof(char)*10);
	}
	printf("Enter the Expression :\t");
	yylex();
	if(invalid==0 && bracket==0 && exOperand==0){
		printf("\bNumber of operands = %d\nNumber of Operators = %d",op,(mul+plus));
		printf("\nOperands :");
		for(k=0;k<i;++k) printf("%s",operand[k]);
		printf("\nOperators :");
		for(k=0;k<j;++k) printf("%s",operator[k]);
	}else
		printf("\nInvalid");
}
