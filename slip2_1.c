/*
Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the FIFO page
replacement algorithm. Assume the memory of n frames.
Reference String : 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6 
*/

#include <stdio.h>

void main(){
	int fc, sl, lr=0, hc=0;
	printf("Enter frame count: ");
	scanf("%d", &fc);
	printf("Enter string length: ");
	scanf("%d", &sl);
	int str[sl], frame[fc];
	
	for(int i=0;i<sl;i++){
		printf("Enter string %d: ", i);
		scanf("%d", &str[i]);
	}
	
	for(int i=0;i<sl;i++){
		int key = str[i],exists=0;
		for(int j=0;j<fc;j++)
			if(key == frame[j]){
				exists = 1;
				hc++;			
			}
		if(exists == 0)
			frame[(lr++ % fc)] = key;
		//printf("\nCurrent frame\n");
		//for(int j=0;j<fc;j++)
			//printf("%d\t", frame[j]);
	}
	printf("Hit count: %d\nPage fault count: %d\n", hc, sl - hc);
}
