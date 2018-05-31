#include<stdio.h>
#include<stdlib.h>

int n=0,r=0;

void check(int need[n][r],int allo[n][r], int avail[r]) {
	int reloop=0,count=0,done[n],prevDone[n],flag=1,i,j;
	for(i=0;i<n;++i)
		prevDone[i]=done[i]=0;
	do{
		reloop=count=0;
		for(i=0;i<n;++i){
			if(done[i]==0){
				flag=1;
				for(j=0;j<r;++j){
					if(avail[j] < need[i][j]){
						flag=0;
						break;
					}
				}
				if(flag==1){
					printf("Process %d\n",(i+1));
					done[i]=1;
					for(j=0;j<r;++j)
						avail[j]+=allo[i][j];
				}
			}
		}
		for(i=0;i<n;++i)
			if(prevDone[i]==done[i])
				++count;
		if(count==n){
			printf("\nUnsafe State Encountered !!\n");
			exit(1);
		}else{
			for(i=0;i<n;++i)
				prevDone[i]=done[i];
		}
		for(i=0;i<n;++i)
			if(done[i]==0){
				reloop=1;
				break;
			}
	}while(reloop);
	printf("\nIt is a safe state !\n");
}

int main() {
	printf("\nHow many Processes ?\t");
	scanf("%d",&n);
	printf("\nHow many Resources ?\t");
	scanf("%d",&r);
	int max[n][r],need[n][r],avail[r],allo[n][r],i,j;
	printf("\nEnter the Allocation Matrix\n");
	for(i=0;i<n;++i)
		for(j=0;j<r;++j)
			scanf("%d",&allo[i][j]);
	printf("\nEnter the Maximum Matrix\n");
	for(i=0;i<n;++i)
		for(j=0;j<r;++j)
			scanf("%d",&max[i][j]);
	printf("\nEnter the Available Resources\n");
	for(j=0;j<r;++j)
		scanf("%d",&avail[j]);
	printf("\nThe Need Matrix is :\n");
	for(i=0;i<n;++i){
		for(j=0;j<r;++j){
			need[i][j] = max[i][j]-allo[i][j];
			printf("%d",need[i][j]);
		}
		printf("\n");
	}
	printf("\nThe Sequence is :\n");
	check(need,allo,avail);
	return 0;
}
