#include <stdio.h>
#include <stdlib.h>

int* banker(int **allocation, int **max, int *available, int nproc, int nresource) {
	int i, j, k;
	int *work = available;
	int **need = (int **)(calloc(nproc,sizeof(int *)));
	for(i = 0; i < nproc; i++) {
		need[i] = (int *)(calloc(nresource, sizeof(int)));
	}
	int *finish = (int *)(calloc(nproc, sizeof(int)));

	int processes_scheduled = 0;
	int flag = 1;
	int allocate_flag = 0;
	int *process = (int *)(calloc(nproc, sizeof(int)));

	for(i = 0; i < nproc; i++) {
		for (j = 0; j < nresource; j++ ) {
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	while(processes_scheduled <= nproc && flag) {
		flag = 1;
		for(i = 0; i < nproc; i++) {
			for(j = 0; j < nresource; j++) {
				if(work[j] > need[i][j]){
					break;
				}
			}
			if(j == nresource && finish[i] == 0) {
				for(k = 0; k < nresource; k++) {
					work[k] += allocation[i][k];
					process[processes_scheduled] = i+1;
					processes_scheduled++;
				}

			}
		}
	}

	return process;

}

int main() {
	int nproc, nresource, i, num;
	int **allocation;
	int **max;
	int *available;

	printf("Enter the number of processes:");
	scanf("%d", &nproc);
	printf("Enter the number of resources:");
	scanf("%d", &nresource);

	allocation = (int **)(calloc(nproc,sizeof(int *)));
	max = (int **)(calloc(nproc,sizeof(int *)));
	available = (int *)(calloc(nresource, sizeof(int)));

	for(i = 0; i < nproc; i++) {
		allocation[i] = (int *)(calloc(nresource, sizeof(int)));
		max[i] = (int *)(calloc(nresource, sizeof(int)));
	}

	printf("Enter the resource instances allocated:\n");
	for(i = 0;i < nproc; i++){
		for(int j = 0; j < nresource; j++) {
			scanf("%d", &allocation[i][j]);
		}
	}
	printf("Enter the resource maximum instances:\n");
	for(i = 0;i < nproc; i++){
		for(int j = 0; j < nresource; j++) {
			scanf("%d", &max[i][j]);
		}
	}

	int *process = banker(allocation, max, nproc, available, nresource);

	printf("The safe sequence is:\n");
	for(i = 0; i < nproc; i++) {
		printf("%4d", process[i]);
	}

	return 0;

}
