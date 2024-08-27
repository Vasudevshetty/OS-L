#include <stdio.h>
#include <limits.h>

typedef struct
{
    int id, at, bt, ct, rt, tat, wt, remainingTime
} Process;

int findMin(Process p[], int n, int currentTime)
{
    int min_index = -1;
    int min_remainingTime = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (p[i].at <= currentTime && p[i].remainingTime > 0)
        {
            min_remainingTime = p[i].remainingTime;
            min_index = i;
        }
    }
    return min_index;
}

void sjf(Process p[], int n)
{
    int elapsed = 0, completed = 0, currentTime = 0;
    int total_wt = 0, total_tat = 0, total_rt = 0;

    printf("GANTT chart\n");

    while (completed < n)
    {
        int min_index = findMin(p, n, currentTime);
        if (min_index == -1)
        {
            printf("|IDLE(%d)", currentTime);
            currentTime++;
            continue;
        }

        if (p[min_index].remainingTime == p[min_index].bt)
            p[min_index].rt = currentTime - p[min_index].at;

        p[min_index].remainingTime--;
        currentTime++;

        if (p[min_index].remainingTime == 0)
        {
            completed++;
            p[min_index].ct = currentTime;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;

            total_rt += p[min_index].rt;
            total_tat += p[min_index].tat;
            total_wt += p[min_index].wt;
        }
    }
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

    printf("Enter the no of process ");
    scanf("%d", &n);
    Process process[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process%d\n", i + 1);
        printf("AT BT Priority: ");
        scanf("%d", &process[i].at);
        scanf("%d", &process[i].bt);
        process[i].id = i + 1;
        process[i].remainingTime = process[i].bt;
        printf("\n");
    }
    priority(process, n);
    return 0;
}