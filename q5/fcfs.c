#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int id, at, rt, bt, ct, tat, wt;
} Process;

void sortProcessesByArrivalTime(Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                Process temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
}

void calculateTimes(Process p[], int n)
{
    int total_tat = 0, total_wt = 0, total_rt = 0;
    int elapsedTime = 0;

    printf("Gantt Chart\n");
    for (int i = 0; i < n; i++)
    {
        if (p[i].at > elapsedTime)
        {
            printf("|IDLE(%d)", p[i].at);
            elapsedTime = p[i].at;
        }
        int temp = elapsedTime;
        p[i].rt = elapsedTime - p[i].at;
        elapsedTime += p[i].bt;
        p[i].ct = elapsedTime;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        printf("|(%d) P%d (%d)", temp, p[i].id, elapsedTime);
        total_rt += p[i].rt;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

    printf("\nAverage turnaround time: %.2f\nAverage waiting time: %.2f\n", (float)total_tat / n, (float)total_wt / n);
}

int main()
{
    int n;
    printf("Enter the no of process: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process%d\n", i + 1);
        printf("Enter the arrival time & burst time of process:");
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i + 1;
        printf("\n");
    }
    sortProcessesByArrivalTime(p, n);
    calculateTimes(p, n);
    return 0;
}
