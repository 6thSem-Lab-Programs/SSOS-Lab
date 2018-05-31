%{
#include<stdio.h>
#include "y.tab.h"
extern yylval;
%}

%%
[\t] {;}
[+|\-|/|*|<|>|=] {printf("\n%s is an Operator",yytext); return OP;}
[0-9]+ {yylval=atoi(yytext);printf("\n%d is a Digit",yylval); return DIGIT;}
[int|void|float|char|bool|if|else|do|while|for|case|switch] {printf("\n%s is a Keyword",yytext); return KEY;}
[a-zA-Z_][a-zA-Z0-9_]+ {printf("\n%s is an Identifier",yytext); return ID;}
. {;}
%%

int yywrap() {
        return 1;
}

