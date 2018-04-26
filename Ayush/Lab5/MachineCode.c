#include<stdio.h>
#include<string.h>

char op[2], arg1[5], arg2[5], result[5];
int main() {
	FILE *fp1, *fp2;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");
	while(!feof(fp1)) {
		strcpy(result,"");
		strcpy(arg1,"");
		strcpy(arg2,"");
		strcpy(op,"");
		fscanf(fp1, "%s%s%s%s", result, arg1, op, arg2);
		if((arg1[0]=='-'&& isalpha(arg1[1]))) {
			strcpy(arg1,(index(arg1,'-') + 1));
			fprintf(fp2,"\nMUL %s, -1",arg1);
		}
		if((arg2[0]=='-'&& isalpha(arg2[1]))) {
			strcpy(arg2,(index(arg2,'-') + 1));
			fprintf(fp2,"\nMUL %s, -1",arg2);
		}
		if(strcmp(op,"+")==0) {
			fprintf(fp2,"\nMOV R0, %s",arg1);
			fprintf(fp2,"\nADD R0, %s",arg2);
			fprintf(fp2,"\nMOV %s, R0\n",result);
		}
		if(strcmp(op,"-")==0) {
			fprintf(fp2,"\nMOV R0, %s",arg1);
			fprintf(fp2,"\nSUB R0, %s",arg2);
			fprintf(fp2,"\nMOV %s, R0\n",result);
		}
		if(strcmp(op,"*")==0) {
			fprintf(fp2,"\nMOV R0, %s",arg1);
			fprintf(fp2,"\nMUL R0, %s",arg2);
			fprintf(fp2,"\nMOV %s, R0\n",result);
		}
		if(strcmp(op,"/")==0) {
			fprintf(fp2,"\nMOV R0, %s",arg1);
			fprintf(fp2,"\nDIV R0, %s",arg2);
			fprintf(fp2,"\nMOV %s, R0\n",result);
		}
		if(strcmp(op,"=")==0) {
			fprintf(fp2,"\nMOV R0, %s",arg1);
			fprintf(fp2,"\nMOV %s, R0\n",result);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 1;
}	
