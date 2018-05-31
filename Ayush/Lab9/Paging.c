#include<stdio.h>
#include<stdlib.h>
int n,nf,i,j,k,pgfltcnt=0,hit=0;
int in[20],p[10];

void getData() {
	printf("\nEnter Length of Page Reference Sequence :\t");
	scanf("%d",&n);
	printf("Enter Page Reference Sequence :\t");
	for(i=0;i<n;++i)
		scanf("%d",&in[i]);
	printf("Enter Number of Frames :\t");
	scanf("%d",&nf);
}

void initialize() {
	pgfltcnt=0;
	for(i=0;i<nf;++i) p[i]=9999;
}

int isHit(int data) {
	hit=0;
	for(j=0;j<nf;++j) 
		if(data==p[j]){
			hit=1;
			break;
		}
	return hit;
}

void dispPages() {
	for(k=0;k<nf;++k) 
		if(p[k]!=9999)
			printf("  %d",p[k]);
}

void dispPgFltCnt() {
	printf("\nTotal number of page faults :\t%d",pgfltcnt);
	printf("\nRate of Page Fault :\t%f\n\n", (float)pgfltcnt/(float)n);
}

void fifo() {
	initialize();
	for(i=0;i<n;++i){
		printf("\n For %d :\t",in[i]);
		if(isHit(in[i])==0){
			for(k=0;k<nf-1;++k)p[k]=p[k+1];
			p[k]=in[i];
			pgfltcnt++;
			dispPages();
		}else
			printf("No Page Fault !");
	}
	dispPgFltCnt();
}

void lru() {
	int least[10];
	initialize();
	for(i=0;i<n;++i){
		printf("\n For %d :\t",in[i]);
		if(isHit(in[i])==0){
			for(j=0;j<nf;++j){
				int pg=p[j],found=0;
				for(k=i-1;k>=0;--k){
					if(pg==in[k]){
						least[j]=k;
						found=1;
						break;
					}else
						found=0;
				}
				if(found==0) least[j]=-9999;
			}
			int min=999,repindex;
			for(j=0;j<nf;++j){
				if(least[j]<min){
					min=least[j];
					repindex=j;
				}
			}
			p[repindex]=in[i];
			pgfltcnt++;
			dispPages();
		}else
			printf("No Page Fault !");
	}
	dispPgFltCnt();
}

int main() {
	int choice;
	do{
		printf("\nMenu\n1. FIFO\n2. LRU\n3. Exit\nEnter Choice :\t");
		scanf("%d",&choice);
		switch(choice) {
			case 1 : getData();
				 fifo();
				 break;
			case 2 : getData();
				 lru();
				 break;
			case 3 : exit(0);
			default: printf("\nInvalid Input !!\n");
		}
	}while(1);
	return 0;
}
