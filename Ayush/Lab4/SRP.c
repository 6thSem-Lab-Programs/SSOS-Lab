#include<stdio.h>
#include<string.h>

char Exp[20],stk[20];
int top=-1,j=0,c;

void check() {
	int k;
	for(k=0;k<c;++k){
		if(stk[k]=='i' && stk[k+1]=='d'){
			stk[k]='F';
			stk[k+1]=' ';
			--top;
			printf("\n$%s\t%s$\tReduce",stk,Exp);
		}
	}
	for(k=0;k<c;++k){
		if(stk[k]=='(' && stk[k+1]=='E' && stk[k+2]==')'){
			stk[k]='F';
			stk[k+1]=' ';
			stk[k+2]=' ';
			top-=2;
			printf("\n$%s\t%s$\tReduce",stk,Exp);
		}
	}
	for(k=0;k<c;++k){
		if(stk[k]=='T' && stk[k+1]=='*' && stk[k+2]=='F'){
			stk[k]='T';
			stk[k+1]=' ';
			stk[k+2]=' ';
			top-=2;
			printf("\n$%s\t%s$\tReduce",stk,Exp);
		}
	}
	for(k=0;k<c;++k){
		if(stk[k]=='F'){
			stk[k]='T';
			printf("\n$%s\t%s$\tReduce",stk,Exp);
		}
	}
	for(k=0;k<c;++k){
		if(stk[k]=='E' && stk[k+1]=='+' && stk[k+2]=='T' && stk[k+3]!='*' && Exp[j]!='*'){
			stk[k]='E';
			stk[k+1]=' ';
			stk[k+2]=' ';
			top-=2;
			printf("\n$%s\t%s$\tReduce",stk,Exp);
		}
	}
	for(k=0;k<c;++k){
		if(stk[k]=='T' && stk[k+1]!='*' && Exp[j]!='*'){
			stk[k]='E';
			printf("\n$%s\t%s$\tReduce",stk,Exp);
		}
	}
}

int main() {
	printf("\nEnter the Expression :\t");
	gets(Exp);
	c = strlen(Exp);
	for(j=0;j<c;){
		if(Exp[j]=='i' && Exp[j+1]=='d'){
			stk[++top]=Exp[j];
			stk[++top]=Exp[j+1];
			stk[top+1]='\0';
			Exp[j]=' ';
			Exp[j+1]=' ';
			j+=2;
			printf("\n$%s\t%s$\tShift",stk,Exp);
			check();
		}else{
			stk[++top]=Exp[j];
			stk[top+1]='\0';
			Exp[j]=' ';
			++j;
			printf("\n$%s\t%s$\tShift",stk,Exp);
			check();
		}

	}
	if(stk[0]=='E' && top==0)
		printf("\nAccepted !\n");
	else
		printf("\nNot Accepted !\n");
	return 0;
}
