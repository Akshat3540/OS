#include <stdio.h>

void main()
{
    
    int i, n;
    int process_num[10], arrival_time[10], burst_time[10];
    int start[10], finish[10], tat[10], wait_time[10];
    float total_wt = 0, total_tat = 0;

    printf("Number of Process = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nProcess Number = ");
        scanf("%d", &process_num[i]);

        printf("\tArrival Time = ");
        scanf("%d", &arrival_time[i]);

        printf("\tBurst Time = ");
        scanf("%d", &burst_time[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start[i] = arrival_time[i];
            wait_time[i] = start[i] - arrival_time[i];
            finish[i] = start[i] + burst_time[i];
            tat[i] = finish[i] - arrival_time[i];
        }
        else
        {
            start[i] = finish[i - 1];
            wait_time[i] = start[i] - arrival_time[i];
            finish[i] = start[i] + burst_time[i];
            tat[i] = finish[i] - arrival_time[i];
        }
    }

    printf("\nProcess Name\tArrival Time\tBurst Time\tStart Time\tTurn Around Time\tFinish Time\t\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", process_num[i], arrival_time[i], burst_time[i], start[i], tat[i], finish[i]);
        total_wt += wait_time[i];
        total_tat += tat[i];
    }
    printf("\nAverage Waiting Time = %f\n", total_wt/n);
    printf("Average Turn Around Time = %f\n", total_tat/n);
}
