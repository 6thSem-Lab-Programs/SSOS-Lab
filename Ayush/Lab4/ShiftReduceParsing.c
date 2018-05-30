#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j=0,top=-1,k,c;
char Exp[20],act[20],stk[20];

void check(){
	k=0;
	for(k=0;k<c;k++){
		
		if(stk[k]=='i'&&stk[k+1]=='d'){
			stk[k]='F';
			stk[k+1]=' ';
			top--;
			printf("$%s\t%s$\t Reduce\n",stk,Exp);
		}
	}
	for(k=0;k<c;k++){
		
		if(stk[k]=='('&& stk[k+1]=='E'&& stk[k+2]==')'){
			stk[k]='F';
			stk[k+1]=' ';
			stk[k+2]=' ';
			top--;
			top--;
			printf("$%s\t%s$\t Reduce\n",stk,Exp);
		}
	}
	for(k=0;k<c;k++){
		
		if(stk[k]=='T'&& stk[k+1]=='*'&&stk[k+2]=='F'){
			stk[k]='T';
			stk[k+1]=' ';
			stk[k+2]= ' ';
			top--;
			top--;
			printf("$%s\t%s$\t Reduce\n",stk,Exp);
		}
	}
	for(k=0;k<c;k++){
		
		if(stk[k]=='F'){
			stk[k]='T';
			printf("$%s\t%s$\t Reduce\n",stk,Exp);
		}
	}
	
	
	for(k=0;k<c;k++){
		
		if(stk[k]=='E'&& stk[k+1]=='+' && stk[k+2]=='T'&& Exp[j]!='*'){
			stk[k]='E';
			stk[k+1]=' ';
			stk[k+2]=' ';
			top--;
			top--;
			printf("$%s\t%s$\t Reduce\n",stk,Exp);
		}
	}
	for(k=0;k<c;k++){
		
		if(stk[k]=='T' && Exp[j]!='*'){
			stk[k]='E';
			printf("$%s\t%s$\t Reduce\n",stk,Exp);
		}
	}
	
}
void main(){
	printf("Enter Expression: ");
	gets(Exp);
	c=strlen(Exp);
	for(j=0;j<c;){
		if(Exp[j] == 'i' && Exp[j+1]=='d'){
			strcpy(act,"Shift");
			stk[++top]=Exp[j];
			stk[++top]=Exp[j+1];
			stk[++top]='\0';
			top--;
			Exp[j]=' ';
			Exp[j+1]=' ';
			printf("$%s\t%s$\t%s\n",stk,Exp,act);
			j=j+2;
			check();
			
		}
		else{
			stk[++top]=Exp[j];
			stk[++top]='\0';
			top--;
			Exp[j]=' ';
			printf("$%s\t%s$\t%s\n",stk,Exp,act);
			j++;
			//not required
			if(stk[top]==')')
			check();
		}

	}
	if(stk[0]=='E'&& top==0){
		printf("Accept\n");
	}
	else{
		printf("not Accepted\n");

	}
}
