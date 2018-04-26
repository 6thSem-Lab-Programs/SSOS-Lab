
#include<stdio.h>
#include<stdlib.h>

int n = 0, r = 0;

void compareNeed(int need[n][r], int avail[r], int allo[n][r]) {
	int i,j,flag=1,reloop=0,done[r],prevDone[r],count;
	for(i=0;i<n;++i) done[i] = prevDone[i] = 0;

	do {
		reloop=0;
		count=0;
		for(i=0;i<n;++i) {
			if(done[i]==0) {
				flag=1;
				for(j=0;j<r;++j) {
					if(avail[j]<need[i][j]) {
						flag=0;
						break;
					}
				}
				if(flag==1) {
					printf("\nProcess %d",(i+1));
					done[i]=1;
					for(j=0;j<r;++j) {
						avail[j] += allo[i][j];
					}
				}
			}
		}
		for(i=0;i<n;++i)
			if(prevDone[i] == done[i]) ++count;
		if(count==n) {
			printf("\n\nUnsafe State !!\n\n");
			exit(0);
		}else {
			for(i=0;i<n;++i)
				prevDone[i] = done[i];
		}
		for(i=0;i<n;++i)
			if(done[i]==0)
				reloop=1;

	}while(reloop);
	printf("\n\nIt is a Safe State !\n\n");
	return;
}

int main() {
	printf("\nEnter the number of processes :\t");
	scanf("%d",&n);
	printf("\nEnter the number of resources :\t");
	scanf("%d",&r);

	int allo[n][r], max[n][r], avail[r], need[n][r],i,j;
	printf("\nEnter the Allocation Matrix :\n");
	for(i=0;i<n;++i) {
		printf("\tFor Process %d :\n",(i+1));
		for(j=0;j<r;++j) {
			scanf("%d",&allo[i][j]);
		}
	}
	printf("\nEnter the Maximum Matrix :\n");
	for(i=0;i<n;++i) {
		printf("\tFor Process %d :\n",(i+1));
		for(j=0;j<r;++j){
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nEnter the Available resources :\n");
	for(j=0;j<r;++j) {
		scanf("%d",&avail[j]);
	}

	printf("\nThe Need Matrix is :\n");
	for(i=0;i<n;++i) {
		printf("\nProcess %d",(i+1));
		for(j=0;j<r;++j) {
			need[i][j] = max[i][j] - allo[i][j];
			printf("%d\t",need[i][j]);
		}
	}

	printf("\n\nSequence is \n");
	compareNeed(need, avail, allo);	
	return 1;
}
