#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void getArray(int n, int arr[n]){
	for(int i=0; i<n; i++){
		printf("%d: ", i);
		scanf("%d", &arr[i]);
	}
}

void printArray(int n, int arr[n]){
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int n, int arr[n]){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	printf("Array after bubble sort\n");
	printArray(n, arr);
}

void insertionSort(int n, int arr[n]){
    for(int i=0; i<n; i++){
        int key = arr[i];
        int j;
        for(j=i-1; j >= 0 && arr[j] > key;j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
    printf("Array after insertion sort\n");
    printArray(n, arr);
}

void main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter your array:\n");
	getArray(n, arr);
	printf("Your input array is:\n");
	printArray(n, arr);
	
	int pid;
	pid = fork();
	
	if(pid == 0){
		printf("This child process (%d) with parent (%d)\n", getpid(), getppid());
		insertionSort(n, arr);
	} else if(pid > 0){
		printf("This parent process (%d) \n", getpid());
		bubbleSort(n, arr);
	} else {
		printf("Error forking process \n");
	}
}
