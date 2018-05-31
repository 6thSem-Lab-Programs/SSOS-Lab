#include<stdio.h>
#include<string.h>
#include<ctype.h>

char res[5],op[5],arg1[5],arg2[5];

int main() {
	FILE *fin,*fout;
	fin = fopen("input.c","r");
	fout = fopen("output.c","w");
	while(!feof(fin)){
		strcpy(res,"");
		strcpy(op,"");
		strcpy(arg1,"");
		strcpy(arg2,"");
		fscanf(fin,"%s%s%s%s",res,arg1,op,arg2);
		if(arg1[0]=='-' && isalpha(arg1[1])){
			strcpy(arg1,index(arg1,'-')+1);
			fprintf(fout,"\nMUL %s,-1\n",arg1);
		}
		if(arg2[0]=='-' && isalpha(arg2[1])){
			strcpy(arg2,index(arg2,'-')+1);
			fprintf(fout,"\nMUL %s,-1\n",arg2);
		}
		if(strcmp(op,"+")==0){
			fprintf(fout,"\nMOV R0,%s",arg1);
			fprintf(fout,"\nADD R0,%s",arg2);
			fprintf(fout,"\nMOV %s,R0\n",res);
		}
		if(strcmp(op,"-")==0){
			fprintf(fout,"\nMOV R0,%s",arg1);
			fprintf(fout,"\nSUB R0,%s",arg2);
			fprintf(fout,"\nMOV %s,R0\n",res);
		}
		if(strcmp(op,"*")==0){
			fprintf(fout,"\nMOV R0,%s",arg1);
			fprintf(fout,"\nMUL R0,%s",arg2);
			fprintf(fout,"\nMOV %s,R0\n",res);
		}
		if(strcmp(op,"/")==0){
			fprintf(fout,"\nMOV R0,%s",arg1);
			fprintf(fout,"\nDIV R0,%s",arg2);
			fprintf(fout,"\nMOV %s,R0\n",res);
		}
		if(strcmp(op,"=")==0){
			fprintf(fout,"\nMOV R0,%s",arg1);
			fprintf(fout,"\nMOV %s,R0\n",res);
		}
	}
	fclose(fout);
	fclose(fin);
	return 0;
}
