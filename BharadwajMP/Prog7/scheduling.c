#include<stdio.h>
#include<stdlib.h>

void srt(int n,int *burst,int *atime)
{
	int i,po=0,pi = 0,lBurst = 999,rt = 0,time = 999,st = 0;
	printf("Enter arrival time for:\n");

	int wt[n],tat[n];
	
	for(i = 0;i < n;i++)
	{
		wt[i] = 0;
		tat[i] = 0;
	}

	for(i = 0;i < n;i++)
		if(atime[i] <= time && burst[i] < lBurst)
		{
			pi = i;
			time = atime[i];
			lBurst = burst[i];
		}
	st = time;

	for(i = 0;i < n;i++)
		rt += burst[i];

	printf("Time\tProcess\tRemaining burst time\n");

	while(rt != 0)
	{
		lBurst = 999;
		po = pi;
		for(i = 0;i < n;i++)
		{
			if(atime[i] <= time && burst[i]!=0)
			{
				if(burst[i] < lBurst)
				{
					pi = i;
					lBurst = burst[i];
				}
			}
		}
		burst[pi]--;

		for(i = 0;i < n;i++)
			if(burst[i] != 0 && i != pi && atime[i] <= time)
				wt[i]++;

		if(po != pi)
		{
			printf("%d-%d\t%3d\t%8d\n",st,time,(po+1),burst[po]);
			st = time;
		}

		rt = 0;

		for(i = 0;i < n;i++)
			rt += burst[i];	
		time++;

		if(burst[pi] == 0)
			tat[pi] = time - atime[pi];
	}
	float awt = 0,atat = 0;
	printf("%d-%d\t%3d\t%8d\n",st,time,(pi+1),burst[pi]);
	printf("Process\tWaiting Time\tTurn Around Time\n");
	for(i = 0;i < n;i++)
	{
		printf("%3d%8d%16d\n",(i+1),wt[i],tat[i]);
		awt += wt[i];
		atat += tat[i];
	}

	printf("Average waiting time = %.2f\nAverage turn around time = %.2f\n",(awt/n),(atat/n));

}

void rr(int n,int *burst,int *atime)
{
	int quantum = 0,wt[n],tat[n],i,j,rt = 999,time = 0,t;

	for(i = 0;i < n;i++)
	{
		wt[i] = 0;
		tat[i] = 0;
	}

	printf("Enter quantum size : ");
	scanf("%d",&quantum);
	printf("\n");
	
	printf("Time\tProcess\tRemaining burst time\n");
	while(rt != 0)
	{
		rt = 0;
		for(i = 0;i < n;i++)
		{	
			if(burst[i] != 0 && atime[i] <= time)
			{
				if(burst[i] >= quantum)
				{
					burst[i] -= quantum;
					t = quantum;
					printf("%d-%d\t%3d\t%8d\n",time,(time+t),(i+1),burst[i]);
				}
				else
				if(burst[i] < quantum)
				{
					t = burst[i];
					printf("%d-%d\t%3d\t%8d\n",time,(time+t),(i+1),burst[i]);
					burst[i] = 0;
				}
				for(j = 0;j < n;j++)
					if(burst[j] != 0 && i != j && atime[j] <= time)
						wt[j] += t;
				time += t;
				rt+=burst[i];
				if(burst[i] == 0)
					tat[i] = time - atime[i];
				
		//		printf("Time = %d\n",(time+t));
		//		for(j = 0;j < n;j++)
		//			printf("%3d%8d%16d\n",(j+1),wt[j],tat[j]);


			}
		}
	}
	float awt = 0,atat = 0;
	printf("Process\tWaiting Time\tTurn Around Time\n");
		for(i = 0;i < n;i++)
		{
			printf("%3d%8d%16d\n",(i+1),wt[i],tat[i]);
			awt += wt[i];
			atat += tat[i];
		}
	printf("Average waiting time = %.2f\nAverage turn around time = %.2f\n",(awt/n),(atat/n));
}

int main()
{
	int n;

	printf("Enter number of processes\n");
	scanf("%d",&n);

	if(n <= 0)
	{
		printf("Invalid input\n");
		exit(-1);
	}

	int burst[n],atime[n];

	printf("Enter burst time for:\n");

	int i;

	for(i = 0;i < n;i++)
	{
		printf("Process %d : ",(i+1));
		scanf("%d",&burst[i]);
		printf("\n");
	}

	printf("Enter arrival time for:\n");

	for(i = 0;i < n;i++)
	{
		printf("Process %d : ",(i+1));
		scanf("%d",&atime[i]);
		printf("\n");
	}

	int choice = 1;

	printf("Which scheduling algorithm to use :\n1-Shortest remaining time\n2-Round robin\n");
	scanf("%d",&choice);

	if(choice != 1 && choice != 2)
	{
		printf("Invalid input\n");
		exit(-2);
	}

	if(choice == 1)
		srt(n,burst,atime);
	else

	if(choice == 2)
		rr(n,burst,atime);
}
