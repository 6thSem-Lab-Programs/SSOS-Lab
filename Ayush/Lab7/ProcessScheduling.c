#include<stdio.h>
#include<stdlib.h>

void srt(int n, int burst[], int atime[]) {
	int pi=0,po=0,i,lBurst=99,time=999,rt=0,st=0;
	int wt[n],tat[n];
	for(i=0;i<n;++i)
		tat[i]=wt[i]=0;
	rt=0;
	for(i=0;i<n;++i)
		rt+=burst[i];
	for(i=0;i<n;++i){
		if(burst[i]<lBurst && atime[i]<=time){
			pi=i;
			time=atime[i];
			lBurst=burst[i];
		}
	}
	st=time;

	printf("\nTime\tProcess\tRemaining Burst\n");
	while(rt!=0){
		lBurst=999;
		po=pi;
		for(i=0;i<n;++i){
			if(burst[i]!=0 && atime[i]<=time){
				if(burst[i]<lBurst){
					pi=i;
					lBurst=burst[i];
				}
			}
		}
		burst[pi]--;
		for(i=0;i<n;++i)
			if(burst[i]!=0 && i!=pi && atime[i]<=time)
				wt[i]++;
		if(po!=pi){
			printf("%d-%d\t%d\t%d\n",st,time,(po+1),burst[po]);
			st=time;
		}
		rt=0;
		for(i=0;i<n;++i)
			rt+=burst[i];
		time++;
		if(burst[pi]==0)
			tat[pi]=time-atime[pi];		
	}
	printf("%d-%d\t%d\t%d\n",st,time,(pi+1),burst[pi]);

	float awt=0,atat=0;
	printf("\nProcess\tWT\tTAT\n");
	for(i=0;i<n;++i){
		printf("%d\t%d\t%d\n",(i+1),wt[i],tat[i]);
		awt+=wt[i];
		atat+=tat[i];
	}
	printf("\nAverage WT :\t%f\nAverage TAT :\t%f\n",(awt/n),(atat/n));
}

void rr(int n, int burst[], int atime[]) {
	int quantum=0,i,j,time=999,rt=0,t=0;
        int wt[n],tat[n];
	printf("\nEnter the Quantum size :\t");
	scanf("%d",&quantum);
        for(i=0;i<n;++i)
                tat[i]=wt[i]=0;
        rt=0;
        for(i=0;i<n;++i)
                rt+=burst[i];
        for(i=0;i<n;++i)
                if(atime[i]<=time)
                        time=atime[i];
	printf("\nTime is :\t%d\n",time);
	printf("\nTime\tProcess\tRemaining Burst\n");
	while(rt!=0){
		for(i=0;i<n;++i){
			if(burst[i]!=0 && atime[i]<=time){
				if(burst[i]>=quantum){
					burst[i]-=quantum;
					t=quantum;
					printf("%d-%d\t%d\t%d\n",time,(time+t),(i+1),burst[i]);
				}else if(burst[i]<quantum) {
					t=burst[i];
					burst[i]=0;
					printf("%d-%d\t%d\t%d\n",time,(time+t),(i+1),burst[i]);
				}
				for(j=0;j<n;++j)
					if(burst[j]!=0 && i!=j && atime[j]<=time)
						wt[j]+=t;
				time+=t;
        			rt=0;
      				for(j=0;j<n;++j)
                			rt+=burst[j];
				if(burst[i]==0)
					tat[i]=time-atime[i];		
			}
		}
	}

	float awt=0,atat=0;
	printf("\nProcess\tWT\tTAT\n");
	for(i=0;i<n;++i){
		printf("%d\t%d\t%d\n",(i+1),wt[i],tat[i]);
		awt+=wt[i];
		atat+=tat[i];
	}
	printf("\nAverage WT :\t%f\nAverage TAT :\t%f\n",(awt/n),(atat/n));
}


int main() {
	int n,i,choice;
	printf("\nhow many processes ?\t");
	scanf("%d",&n);
	int atime[n],burst[n];
	printf("\nEnter Burst time for\n");
	for(i=0;i<n;++i){
		printf("Process %d :\t",(i+1));
		scanf("%d",&burst[i]);
	}
	printf("\nEnter Arrival time for\n");
	for(i=0;i<n;++i){
		printf("Process %d :\t",(i+1));
		scanf("%d",&atime[i]);
	}
	printf("\nMENU\n");
	printf("1. SRT\n2. RR\n3. Exit\nEnter Choice :\t");
	scanf("%d",&choice);	
	switch(choice) {
		case 1 : srt(n,burst,atime);
			 break;
		case 2 : rr(n,burst,atime);
			 break;
		case 3 : exit(0);
		default: printf("\nInvalid Input !\n"); 
	}
	return 0;
}
