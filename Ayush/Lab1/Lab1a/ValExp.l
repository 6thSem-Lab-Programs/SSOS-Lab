%{
#include<stdio.h>
#include<string.h>
int op=0,mul=0,plus=0,invalid=0,bracket=0,exOperand=0,exOperator=0,exClosingBkt=0,i=0,j=0;
char operand[20][5],operator[20][5];
%}

%%
[0-9]+ {strcpy(operand[i++],yytext);
	op++;
	exOperand=0;
	exOperator=1;
	if(bracket>0) exClosingBkt++;
	}
[(] {bracket++;}
[)] {if(exClosingBkt>=1){
		bracket--;
		exClosingBkt--;
	}else 
		invalid=1;
	}
[+|*] {strcpy(operator[j++],yytext);
	if(exOperator==1){
		if(yytext[0]=='+')plus++;
		else if(yytext[0]=='*')mul++;
		exOperator=0;
		exOperand=1;
	}else if(exOperator==0){
		invalid=1;
	}else if(exOperand==1)
		invalid=1;
	}
. {invalid=1;}
%%

int main() {
	int k;
	printf("\nEnter the Expression :\t");
	yylex();
	if(invalid==0 && exOperand==0 && bracket==0) {
		printf("\nNumber of Operands  :\t%d\n",op);
		printf("\nNumber of Operators :\t%d\n",(plus+mul));
		printf("\nList of Operands :\n");
		for(k=0;k<i;++k)
			printf("\t%s\n",operand[k]);
		printf("\nList of Operators :\n");
		for(k=0;k<j;++k)
			printf("\t%s\n",operator[k]);
		
	}else
		printf("\nInvalid Expression !!\n\n");
	return 0;
}

int yywrap() {
	return 1;
}
