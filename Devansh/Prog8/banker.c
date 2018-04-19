#include <stdio.h>

void main() {
	int n, r, i, j;

	printf("Enter the number of processes : ");
	scanf("%d", &n);
	printf("Enter the number of resources : ");
	scanf("%d", &r);

	int alloc[n][r], max[n][r], need[n][r], avail[r];

	printf("Enter the allocation matrix\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < r; j++) {
			scanf("%d", &alloc[i][j]);
		}
	}

	printf("Enter the max resources matrix\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < r; j++) {
			scanf("%d", &max[i][j]);
		}
	}

	printf("Enter the available resources matrix\n");
	for(i = 0; i < r; i++) {
		scanf("%d", &avail[i]);
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < r; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	int flag = 0, work[r], safe[n], k, s = 0, t;
	for(i = 0; i < r; i++) {
		work[i] = avail[i];
	}

	do {
		flag = 0;
		for(k = 0; k < n; k++) {
			t = 0;
			for(i = 0; i < r; i++) {
				if(work[i] < need[k][i]) {
					t = 1;
					break;
				}
			}
			if(t == 0) {
				safe[s++] = k;
				for(i = 0; i < r; i++) {
					need[k][i] = 9999999;
				}

				if(flag == 0) {
					flag = 1;
				}

				for(i = 0; i < r; i++) {
					work[i] += alloc[k][i];
				}
			}
		}
	} while(flag);

	printf("Safe sequence : ");
	for(i = 0; i < n; i++) {
		printf("%d\t", safe[i]);
	}
	printf("\n");
}

