#include <stdio.h>

void main()
{
    int i, j, n, temp;
    int burst_time[10], process_num[10], tat[10], wait_time[10];
    float total_wt, total_tat;

    printf("Number of Process = ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Burst Time of Process %d = ", i);
        scanf("%d", &burst_time[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (burst_time[i] > burst_time[j])
            {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = process_num[i];
                process_num[i] = process_num[j];
                process_num[j] = temp;
            }
        }
    }
    wait_time[0] = 0;
    for (i = 1; i < n; i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
        total_wt += wait_time[i];
    }

    printf("\nProcess Number\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = burst_time[i] + wait_time[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i, burst_time[i], wait_time[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %f", total_wt/n);
    printf("\nAverage Turn Around Time = %f\n", total_tat/n);
}