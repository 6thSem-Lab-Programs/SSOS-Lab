#include <stdio.h>

int arrival[10], burst[10], temp[10], n, t;

int search(int arr[10], int val) {
	int i;
	for(i = 0; i < 10; i++) {
		if(arr[i] == val) {
			return i;
		}
	}

	return -1;
}

void srf() {
	int i, leastBurst, k, temp;
	i = 0; leastBurst = 999; t = 0;

	while(true) {
		int j;
		for(j = 0; j < n; j++) {
			if(arrival[j] <= t && burst[j] < leastBurst) {
				i = j;
				leastBurst = burst[j];
			}
		}
		k = i;
		burst[i]--;
		temp++;

		if() {
		}
	}
}

void rr() {
	int q, p;
	printf("Enter quantum size : ");
	scanf("%d", &q);

	t = 0;
	while(true) {
		p = search(arrival, t);
		if(p != -1) {

		}

		t++;
	}
}

void main() {
	int i, ch;

	printf("Enter the number of processes : ");
	scanf("%d", &n);

	printf("Enter the process arrival times and burst times :\n");
	for(i = 0; i < n; i++) {
		scanf("%d%d", &arrival[i], &burst[i]);
	}
	for(i = n; i < 10; i++) {
		arrival[i] = -1;
		burst[i] = -1;
	}

	printf("\tM E N U\n1. Shortest Remaining Time\n2. Round Robin\nEnter your choice : ");
	scanf("%d", &ch);

	switch(ch) {
		case 1:
			srf();
		break;
		case 2:
			rr();
		break;
	}
}

