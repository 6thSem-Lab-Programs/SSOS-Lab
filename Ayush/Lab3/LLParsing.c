#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char rules[3][10];
char message[100];
int M[6][2]; 
/* Holds the indexes to the rules and their firsts 

	A->aBa 	index = 0  			input_symbol = {'a','b','$'}
	B->bB	index = 1							 0   1   2
	B-@ 	index = 2	
	
	After first instruction M = {0, 0} which means that rules[0] and input_symbol[0] that is 'A->aBa' and 'a'
*/
char find_first(char *);					/* return the first of the non-terminal*/
int check_follow(char (*)[10], char, char); /* Check if the symbol is a follow of the non-terminal */
char input_symbol[4];
void pop(char *, int*);	
void push(char *, int *, int);
void parse_output();
int main(int argc, char *argv[])
{
	int i = 0, j = 0, k = 0;;
	M[0][0] = M[1][0] = M[2][0] = M[3][0] = M[4][0] = M[5][0] = 99;
	printf("Enter the rules\n");
	for(i = 0; i<3; i++) {
		printf("Enter rule %d: ",i);
		scanf("%s",rules[i]);
	}
	strcpy(input_symbol, "ab$");
	for(i = 0; i<3; i++) {
		for(j = 0; j<3; j++) {
			if(find_first(rules[i]) == input_symbol[j])	 {
				M[k][0] = i; /* Assing the index of the rule*/
				M[k][1] = j; /* Assign the index of input_symbol */
				k++;
			}

			else {
				if(find_first(rules[i]) == '@') {
					if(check_follow(rules,rules[i][0],input_symbol[j])) {
						M[k][0] = i;
						M[k][1] = j;
						k++;
					}
				}
			}
		}
	}

	for(i = 0; i<6 && (M[i][0] != 99); i++) {
		printf("M[%c, %c] = %s\n",rules[M[i][0]][0], input_symbol[M[i][1]], rules[M[i][0]]);
	}

	parse_output();
}

char find_first(char *rules) 
{
	while((*rules++) != '>')
		;
	
	if(islower(*rules)||(*rules == '@'));
		return *rules;
}

int check_follow(char rules[][10], char a, char ip_sym)
{
	int i = 0, j = 0;
	for(i = 0; i<10; i++) 
		for(j = 0; j<10; j++) 
			if(rules[i][j] == a) {
				if((i == 0) && (j==0) && ip_sym == '$')  /* if the non-terminal is the start symbol*/
					return 1;
				else if((rules[i][j+1] != '-') && (rules[i][j+1]==ip_sym)) /*it should not be on LHS and its follow matches*/
					return 1;
			}
	return 0;
}

void parse_output()
{
	char stack[100];
	int top = -1;
	int i = 0, k = 0;
	stack[++top] = '$';
	stack[++top] = 'A';
	char input[10];
	printf("Enter the input: ");
	scanf("%s",input);
	printf("%10s %10s %20s\n","Stack","Input","Actions");
	printf("\n%10s %10s$ %20s\n",stack, input, message);
	while(input[i] != '\0') {
		if(stack[top] == input[i]) {	/* if the top of stack is same as that of input character then pop it */
			pop(stack, &top);
			input[i] = ' ';
			printf("%10s %10s$ %20s\n",stack, input, message);
			i++;
		}

		else {	
			for(k = 0; k<6 && M[k][0]!=99; k++) {
				/* if the top of stack is a non-terminal*/
				if((rules[M[k][0]][0] == stack[top]) && (input_symbol[M[k][1]] == input[i])) { 
					pop(stack,&top);
					printf("%10s %10s$ %20s\n",stack, input, message);
					push(stack, &top, M[k][0]);
					printf("%10s %10s$ %20s\n",stack, input, message);
				}
			}
		}
	}
}

void pop(char *stack, int *top)
{
	strcpy(message,"poped: ");
	strcat(message, &stack[*top]);
	stack[*top] = '\0';
	*top = *top-1;
}

void push(char *stack, int *top, int index) {
	int x = strlen(rules[index]) - 1;
	if(rules[index][x] != '@')
	for( ; (x>=0) && (rules[index][x] != '>'); x--) {
		stack[++(*top)] = rules[index][x];
	}
	strcpy(message, "pushed: ");
	strcat(message, rules[index]);
}
