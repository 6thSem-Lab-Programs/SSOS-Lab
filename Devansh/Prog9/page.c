#include <stdio.h>

int n, fsize;

int lsearch(int arr[], int size, int item) {
	int i;

	for (i = 0; i < size; i++) {
		if(arr[i] == item) {
			return i;
		}
	}

	return -1;
}

void lru(int pages[n], int frame[fsize]) {
	int i, j, cap = 0, temp = 999, pos;
	int ts[fsize];

	for (i = 0; i < fsize; i++) {
		ts[i] = -1;
	}

	for (i = 0; i < n; i++) {
		printf("Page %d : ", pages[i]);

		if((pos = lsearch(frame, fsize, pages[i])) != -1) {
			ts[pos] = temp--;

			printf("Page already in memory.\n");
		} else {
			if(cap < fsize) {
				frame[cap] = pages[i];
				ts[cap] = temp--;
				cap++;

				printf("Page fault occured. Page inserted into memory without replacement.\n");
			} else {
				int max = 0, maxpos;
				for (j = 0; j < fsize; j++) {
					if(ts[j] > max) {
						max = ts[j];
						maxpos = j;
					}
				}

				frame[maxpos] = pages[i];

				printf("Page fault occured. Replaced page %d in memory.\n", pages[maxpos]);
			}
		}
	}

	printf("Frame : ");
	for(i = 0; i < fsize; i++) {
		printf("%d\t", frame[i]);
	}
	printf("\n");
}

void fifo(int pages[n], int frame[fsize]) {
	int i, j, page_fault = 1, top = -1;

	for(i = 0; i < fsize; i++) {
		frame[i] = 0;
	}

	for(i = 0; i < n; i++) {
		printf("Page %d : ", pages[i]);
		page_fault = 1;

		for(j = 0; j <= top && top != -1; j++) {
			if(frame[j] == pages[i]) {
				page_fault = 0;
				break;
			}
		}

		if(page_fault) {
			if(top < fsize - 1) {
				frame[++top] = pages[i];
				printf("Page fault occured. Page inserted into memory without replacement.\n");
			}
			else{
				printf("Page fault occured. Replaced page %d in memory.\n", frame[0]);
				for(j = 0; j < top; j++) {
					frame[j] = frame[j + 1];
				}
				frame[fsize - 1] = pages[i];
			}
		}
		else{
			printf("Page already in memory.\n");
		}
	}

	printf("Frame : ");
	for(i = 0; i < fsize; i++) {
		printf("%d\t", frame[i]);
	}
	printf("\n");
}

void main() {
	int i, choice;

	printf("Enter the number of page references : ");
	scanf("%d", &n);

	int pages[n];

	printf("Enter the page request seqeunce : ");
	for (i = 0; i < n; i++) {
		scanf("%d", &pages[i]);
	}

	printf("Enter the frame size : ");
	scanf("%d", &fsize);

	int frame[fsize];

	printf("1. LRU\n2. FIFO\nEnter your choice : ");
	scanf("%d", &choice);

	switch(choice) {
		case 1:
		lru(pages, frame);
		break;
		case 2:
		fifo(pages, frame);
		break;
	}
}
