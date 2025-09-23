#include <stdio.h>

typedef struct Process {
	char pid[10];
	int bt,wt,ct,tat,at,st;
} Process;

void printTable(char name[20],int n, Process q[n]){
	printf("%s\nProcess\tBT\tAT\tST\tCT\tWT\tTAT\n", name);
	for(int i=0;i<n;i++)
		printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", q[i].pid, q[i].bt, q[i].at, q[i].st, q[i].ct, q[i].wt, q[i].tat);
	printf("\n");
}

void main(){
	Process q[4];
	for(int i=0;i<4;i++){
		scanf("%s%d%d", q[i].pid, &q[i].bt, &q[i].at);
		q[i].wt = q[i].ct = q[i].st = q[i].tat = 0;
	}
	int t=0;
	printTable("Input", 4, q);
	for(int i=0;i<4;i++)
		for(int j=i+1;j<4;j++)
			if(q[i].at > q[j].at){
				Process t = q[j];
				q[j]=q[i];
				q[i]=t;
			}
	printTable("After sorting", 4, q);
	printf("\nProcessing....\nGantt Chart\n");
	for(int i=0;i<4;i++){
		printf("|%s (%d-%d)|", q[i].pid, t, t + q[i].bt);
		if(i == 0)
			q[i].ct = q[i].bt;
		else
			q[i].ct = q[i].bt + q[i-1].ct;
		q[i].tat = q[i].ct - q[i].at;
		q[i].st = ( i == 0 ? 0 : (q[i].ct - q[i].at));
		q[i].wt = q[i].st - q[i].at;
		t = t + q[i].bt;
	}
	printTable("Output table", 4, q);
	float aat=0, atat=0;
	for(int i=0;i<4;i++){
		aat = q[i].wt;
		atat = atat + q[i].tat;
	}
	printf("Average waiting time: %0.2f\nAverage turn around time: %0.2f\n", aat / 4, atat / 4);
}
