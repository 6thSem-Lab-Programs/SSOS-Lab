#include<stdio.h>
#include<stdlib.h>

int quantum = 0;

void RR(int n,int *arrival, int *burst) {
	printf("Enter the Quantum : \t");
	scanf("%d",&quantum);
	int i,rt=999,time=0;
	printf("Time\tProcess\tRemaining Burst Time\n");
	while(rt!=0) {
		rt=0;
		for(i=0;i<n;++i) {
		    if(burst[i]!=0) {
			if(burst[i]>=quantum) {	
				time+=quantum;
				burst[i]-=quantum;
				printf("%d-%d\t%d\t%d\n",(time-quantum),time,(i+1),burst[i]);
			} else {
				time+=burst[i];
				printf("%d-%d\t%d\t%d\n",(time-burst[i]),time,(i+1),burst[i]);
				burst[i]=0;
			}
			rt+=burst[i];
		    }
		}
	}
	
}

void SRT(int n,int *arrival, int *burst) {
	int i, po=0,pi=0,lburst=999,rt=0,time=999,st=0;
	for(i=0;i<n;++i) rt+=burst[i];

	for(i=0;i<n;++i)
			if(arrival[i]<=time && lburst > burst[i]) {
				po=i;
				time = arrival[i];
				lburst = burst[i];
			}
			printf("%d\n\n",(po+1));
	pi = po;
	printf("Time\tProcess\tRemaining Burst Time\n");
	while(rt!=0) {
		lburst=999;
		po=pi;
		for(i=0;i<n;++i)
			if(arrival[i]<=time && burst[i]!=0 && burst[i]<lburst) {
				pi=i;
				lburst=burst[i];
			}
		burst[pi]--;
		if(po!=pi) {
			printf("%d-%d\t%d\t%d\n",st,time,(po+1),burst[po]);
			st=time;
		//	printf("%d-%d\t%d\t%d\n",st,time,(po+1),burst[po]);
		}
		rt=0;
		for(i=0;i<n;++i) rt+=burst[i];
		time++;
	}
	printf("%d-%d\t%d\t%d\n",st,time,(po+1),burst[po]);
}

int main() {
	int n=0,i;
	printf("\nEnter the number of processes :\t");
	scanf("%d",&n);
	int arrival[n], burst[n],p1[n];
	for(i=0;i<n;++i) {
		printf("\nFor Process %d",(i+1));
		printf("\n  Enter Arrival time : \t");
		scanf("%d",&arrival[i]);
		printf("\n  Enter Burst time   : \t");
		scanf("%d",&burst[i]);
	}
	do {
		int ch=0,i;
		for(i=0;i<n;++i)
			p1[i] = burst[i];
		printf("\n1. SRT\n2. Round Robin\n3. Exit\nEnter Choice :\t");
		scanf("%d",&ch);
		switch(ch) {
			case 1 : SRT(n,arrival,p1);
				 break;
			case 2 : RR(n,arrival,p1);
				 break;
			case 3 : exit(0);
			default: printf("\nInvalid Input !");
		}
	}while(1);
	return 0;
}
