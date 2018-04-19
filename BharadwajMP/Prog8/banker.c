#include <stdio.h>
int pn,rn;
void banker(int al[pn][rn],int need[pn][rn],int avail[]){
	int work[rn];
	int i,safe[pn];

	for(i = 0;i < rn;i++)
		work[i] = avail[i];
	int processed = 0,oldproc=-1;
	while(oldproc != processed && processed < pn){
		oldproc = processed;
		for(i = 0;i < pn;i++){
			int j,n=0;
			for(j = 0; j< rn;j++)
				if(need[i][j] <= work[j])
					n++;
			if(n == rn){
				int k;
				for(k = 0;k < rn;k++){
					work[k] += al[i][k];
					need[i][k] = 999;
				}
				safe[processed++] = i+1;
			}

		}
	}

	if(oldproc == processed)
		printf("Deadlock occured\n");
	else{
		printf("Safe sequence: ");
		for(i = 0;i < pn;i++)
			printf("%d ",safe[i]);
		printf("\n");
	}	
}

void main(){
	printf("Enter number of processes\n");
	scanf("%d",&pn);

	printf("Enter number of resources\n");
	scanf("%d",&rn);

	int max[pn][rn],al[pn][rn],need[pn][rn],avail[rn];
	int a[pn];
	printf("Enter max matrix\n");
	int i,j;

	for(i = 0;i < pn;i++)
		for(j = 0;j < rn;j++)
			scanf("%d",&max[i][j]);

	printf("Enter allocation matrix\n");

	for(i = 0;i < pn;i++)
		for(j = 0;j < rn;j++)
			scanf("%d",&al[i][j]);

	printf("Enter available resource number\n");

	for(i = 0;i < rn;i++)
		scanf("%d",&avail[i]);

	for(i = 0;i < pn;i++)
		for(j = 0;j < rn;j++)
			need[i][j] = max[i][j] - al[i][j];

	banker(al,need,avail);
}
