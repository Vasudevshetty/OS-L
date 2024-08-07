#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int id, at, bt, ct, tat, rt, wt, priority, isCompleted;
} Process;

int findMin(Process p[], int n, int currentTime)
{
    int min_index = -1;
    int min_priority = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (p[i].at <= currentTime && p[i].isCompleted != 1)
        {
            if (p[i].priority < min_priority)
            {
                min_priority = p[i].priority;
                min_index = i;
            }
        }
    }
    return min_index;
}

void priority(Process p[], int n)
{
    int total_wt = 0, total_rt = 0, total_tat = 0;
    int completed = 0;
    int currentTime = 0;

    printf("Gantt chart\n");
    while (completed < n)
    {
        int min_index = findMin(p, n, currentTime);
        if (min_index == -1)
        {
            printf("|IDLE(%d)", currentTime);
            currentTime++;
            continue;
        }

        currentTime += p[min_index].bt;
        printf("|(%d) P%d (%d)", currentTime - p[min_index].bt, p[min_index].id, currentTime);

        completed++;
        p[min_index].ct = currentTime;
        p[min_index].tat = p[min_index].ct - p[min_index].at;
        p[min_index].wt = p[min_index].tat - p[min_index].bt;
        p[min_index].rt = currentTime - p[min_index].bt - p[min_index].at;

        total_rt += p[min_index].rt;
        total_tat += p[min_index].tat;
        total_wt += p[min_index].wt;

        p[min_index].isCompleted = 1;
    }
    printf("|\n");

    printf("PID\tAT\tBT\tCT\tTT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    printf("AVG TT=%.2f\n", (float)total_tat / n);
    printf("AVG WT=%.2f\n", (float)total_wt / n);
    printf("AVG RT=%.2f\n", (float)total_rt / n);
}

int main()
{
    int n;
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t", i + 1);
        printf("Enter AT & Bt & priority: ");
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);

        p[i].id = i + 1;
        p[i].isCompleted = 0;
    }

    priority(p, n);
    return 0;
}