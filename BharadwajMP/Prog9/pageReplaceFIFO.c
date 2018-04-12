#include <stdio.h>

void fifo(int n,int *pages,int frames){
	int memory[frames],i,j,page_fault = 1,top = -1;

	for(i = 0;i < frames;i++)
		memory[i] = 0;

	for(i = 0;i < n;i++){
		page_fault = 1;

		for(j = 0;j <=top && top != -1;j++){
			if(memory[j] == pages[i]){
				page_fault = 0;
				break;
			}
		}
		if(page_fault){
			if(top < frames - 1){
				memory[++top] = pages[i];
				printf("Page %d : Page fault occured!! Page added to memory without any replacement\n",pages[i]);
			}
			else{
				printf("Page %d : Page fault occured!! Replaced Page %d im memory\n",pages[i],memory[0]);
				for(j = 0;j < top;j++)
					memory[j] = memory[j+1];
				memory[frames -1 ] = pages[i];
			}
		}
		else{
			printf("Page %d : Page already present in memory\n",pages[i]);
		}

		
/*		printf("Queue : ");
		for(j = 0;j <= top && top!= -1;j++)
			printf("%d ",memory[j]);
		printf("\n");*/
	}
}

void main(){
	int n;

	printf("Enter number of page reference sequence\n");
	scanf("%d",&n);

	int pages[n];

	printf("Enter page sequence\n");
	int i;
	for(i = 0;i < n;i++)
		scanf("%d",&pages[i]);
	int frames;
	printf("Enter number of frames\n");
	scanf("%d",&frames);

	fifo(n,pages,frames);
}
