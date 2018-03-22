#include<stdio.h>
#include<stdlib.h>

void srt(int n,int *burst,int *atime)
{
	int i,po=0,pi = 0,lBurst = 999,rt = 999,time = 0;

	printf();
	while(rt != 0)
	{
		rt = 0;
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

		if(po != pi)
		{
			printf()
		}	
		
	}
}

void rr(int n,int *burst)
{
	int quantum = 0;

	printf("Enter quantum size : ");
	scanf("%d",&quantum);
	printf("\n");
	int i,rt = 999,time = 0;
	printf("Time\tProcess\tRemaining burst time\n");
	while(rt != 0)
	{
		rt = 0;
		for(i = 0;i < n;i++)
		{	
			if(burst[i] != 0)
			{
				if(burst[i] >= quantum)
				{
					time += quantum;
					burst[i] -= quantum;
				}
				else
				if(burst[i] < quantum)
				{
					time += burst[n];
					burst[i] = 0;
				}
				rt+=burst[i];

				printf("%3d\t%3d\t%8d\n",time,(i+1),burst[i]);
			}
		}
	}
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

	int burst[n];

	printf("Enter burst time for:\n");

	int i;

	for(i = 0;i < n;i++)
	{
		printf("Process %d : ",(i+1));
		scanf("%d",&burst[i]);
		printf("\n");
	}

	printf("Enter arrival time for:\n");

	int atime[n];
	
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
		rr(n,burst);
}
