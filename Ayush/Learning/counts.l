%{
	#include<stdio.h>
	int lineCount = 0;
	int wordCount = 0;
	int charCount = 0; 
%}
	/*int lineCount = 0;
	int wordCount = 0;
	int charCount = 0; */


%%
\n 		{++lineCount;} 
" " 		{++wordCount;} 
[a-z|A-Z|0-9]	{++charCount;} 
%%

int yywrap() {
	return 1;
}

main() {
	//printf("\nEnter the Text : ");
	yylex();
	printf("\n\nLines :\t%d",lineCount);
	printf("\nWords :\t%d",wordCount+lineCount);
	printf("\nChars :\t%d\n\n",charCount+lineCount+wordCount);
}
