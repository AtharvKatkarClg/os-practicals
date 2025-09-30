/*
Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults according to the LRU (using
counter method) page replacement algorithm. Assume the memory of n
frames.
Reference String : 3,5,7,2,5,1,2,3,1,3,5,3,1,6,2 
*/

#include <stdio.h>

int farthestEle(int sl, int fc, int ce, int str, int frame[fc]){
	int ele = frame[0];
	for(int i=0; i<fc; i++){
		for(int j=ce; )
	}
}

void main(){
	int fc, sl, hc = 0, lr;
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
		int key = str[sl], exists = 0;
		for(int j=0;j<fc;j++)
			if(key == frame[j])
				exists = 1;
		if(exists == 0){
			// get farthest element
		}
	}
}
