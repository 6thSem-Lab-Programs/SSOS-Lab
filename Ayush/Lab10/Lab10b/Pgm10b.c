#include<stdio.h>
#include<stdlib.h>
int n,nf,hit=0,i,j,k;
int pgfaultcnt=0;
int in[10],p[50];

void getData() {
	printf("\nEnter length of Page reference sequence :\t");
	scanf("%d",&n);
	printf("Enter the Page reference sequence :\n");
	for(i=0;i<n;++i)
		scanf("%d",&in[i]);
	printf("Enter number of frames :\t");
	scanf("%d",&nf);
}

void initialize() {
	pgfaultcnt=0;
	for(i=0;i<nf;++i) p[i] = 9999;
}

int isHit(int data) {
	hit=0;
	for(j=0;j<nf;++j)
		if(p[j]==data) {
			hit=1;
			break;
		}
	return hit;
}

void dispPages() {
	for(k=0;k<nf;++k)
		if(p[k]!=9999) 
			printf("%d  ",p[k]);
}

void dispPgFaultCnt() {
	printf("\nTotal number of page faults :\t%d",pgfaultcnt);
	float f = ((float)pgfaultcnt)/(float)n;
	printf("\nRate of Page Fault :\t%f\n\n", f);
}

void optimal() {
	initialize();
	int near[50],repindex;
	for(i=0;i<n;++i) {
		printf("\nFor %d :\t",in[i]);
		if(isHit(in[i])==0) {
			for(j=0;j<nf;++j) {
				int pg=p[j];
				int found=0;
				for(k=i;k<n;++k) {
					if(pg==in[j]) {
						near[j]=k;
						found=1;
						break;
					} else 
						found=0;
				}
				if(!found) near[j]=9999;
				int max=-9999;
				repindex;
				for(j=0;j<nf;++j) {
					if(near[j]>max) max=near[j];
					repindex=j;
				}
			}
			p[repindex]=in[i];
			pgfaultcnt++;
			dispPages();
		} else
			printf("No Page Fault !!\n");
	}
	dispPgFaultCnt();
}

void lfu() {

}

void secondChance() {

}

/*void fifo() {
	initialize();
	for(i=0;i<n;++i) {
		printf("\nFor %d :\t",in[i]);
		if(isHit(in[i])==0) {
			for(k=0;k<nf-1;++k) p[k] = p[k+1];
			p[k] = in[i];
			pgfaultcnt++;
			dispPages();
		} else
			printf("\nNo Page Fault !\n");
	}
	dispPgFaultCnt();
}

void lru() {
	initialize();
	int least[50];
	for(i=0;i<n;++i) {
		printf("\nFor %d :",in[i]);
		if(isHit(in[i])==0) {
			for(j=0;j<nf;++j) {
				int pg=p[j];
				int found=0; 
				for(k=i-1;k>=0;k--) {
					if(pg==in[k]) {
						least[j]=k;
						found=1;
						break;
					} else
						found=0;
				}
				if(!found) least[j]=-9999;
			}
			int min=9999;
			int repindex;
			for(j=0;j<nf;++j) {
				if(least[j]<min) {
					min=least[j];
					repindex=j;
				}
			}
			p[repindex]=in[i];
			pgfaultcnt++;
			dispPages();
		} else 
			printf("\nNo Page Fault !\n");
	}
	dispPgFaultCnt();
}*/

int main() {
	int choice=0;
	do {
		printf("\nPage Replacement\n\n1. Optimal\n2. LFU\n3. Second Chance\n4. Exit\nEnter Choice :\t");
		scanf("%d",&choice);
		switch(choice) {
			case 1  : getData();
				  optimal();
				  break;
			case 2  : getData();
				  lfu();
				  break;
			case 3  : getData();
				  secondChance();
				  break;
			case 4  : exit(0);
			default : printf("\nInvalid Input !!\n");
		}
	}while(1);
	return 1;
}
