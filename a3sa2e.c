#include <stdio.h>
struct Process
{
    int pid,AT,BT,CT,TT,WT, is_completed;
};
void printGanttChart(int order[], int n)
{
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) 
    {
        printf(" P%d |", order[i]);
    }
    printf("\n");
}
int main()
 {
    int n, current_time = 0, completed = 0;
    float total_TT = 0, total_WT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    int gantt_order[n];
    for (int i = 0; i < n; i++) 
    {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].AT, &p[i].BT);
        p[i].is_completed = 0;
    }
    while (completed < n)  //
 	{
        int j = -1;
        int min_burst = 100000;  // large number
        for (int i = 0; i < n; i++) 
		{
            if (p[i].AT <= current_time && !p[i].is_completed) 
			{
                if (p[i].BT < min_burst) 
                {
                    min_burst = p[i].BT;
                    j = i;
                } 
                else if (p[i].BT == min_burst)
                 {
                    // Tie breaker: earlier arrival time  fc
                    if (p[i].AT < p[j].AT) 
                    {
                        j = i;
                    }
                }
            }
        }

        if (j != -1) 
        {
            p[j].CT = current_time + p[j].BT;
            p[j].TT = p[j].CT - p[j].AT;
            p[j].WT = p[j].TT - p[j].BT;
            total_TT += p[j].TT;
            total_WT += p[j].WT;
            current_time = p[j].CT;
            p[j].is_completed = 1;
            gantt_order[completed] = p[j].pid;
            completed++;
        } 
        else 
        {
            current_time++;  // idle time j==-1
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].AT, p[i].BT,
               p[i].CT, p[i].TT, p[i].WT);
    }
    printGanttChart(gantt_order, n);
    printf("\nAverage Turnaround Time = %f\n", total_TT / n);
    printf("Average Waiting Time = %f\n", total_WT / n);
    return 0;
}
/********************OUTPUT***********************
Enter number of processes: 4
Enter arrival time and burst time for Process 1: 0 4
Enter arrival time and burst time for Process 2: 1 1
Enter arrival time and burst time for Process 3: 2 2
Enter arrival time and burst time for Process 4: 3 1

Process	AT	BT	CT	TAT	WT
P1	0	4	4	4	0
P2	1	1	5	4	3
P3	2	2	8	6	4
P4	3	1	6	3	2

Gantt Chart:
| P1 | P2 | P4 | P3 |

Average Turnaround Time = 4.25
Average Waiting Time = 2.25 */
