#include <stdio.h>

struct processControlBlock
{
    int id, Priority;
    int burstTime;
    int startTime, completionTime, waitTime, turnAroundTime;
} pcb[20] = {0};

int main()
{
    int i, n, prevProcCompTime = 0;
    int totalWaitTime = 0, totalTurnAroundTime = 0;
    float avgWaitTime, avgTurnAroundTime;

    //Read the process data
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the process details\nProcessId, Priority, Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &pcb[i].id, &pcb[i].Priority, &pcb[i].burstTime);
    }

    //Sorting process id, Priority , Burst Time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pcb[i].Priority > pcb[j].Priority)
            {
                int temp = pcb[i].Priority;
                pcb[i].Priority = pcb[j].Priority;
                pcb[j].Priority = temp;
                temp = pcb[i].burstTime;
                pcb[i].burstTime = pcb[j].burstTime;
                pcb[j].burstTime = temp;
                temp = pcb[i].id;
                pcb[i].id = pcb[j].id;
                pcb[j].id = temp;
            }
        }
    }

    //Using Priority algo, compute start, completition, turn around and wait time.
    for (i = 0; i < n; i++)
    {
        pcb[i].startTime = prevProcCompTime;
        pcb[i].completionTime = pcb[i].startTime + pcb[i].burstTime;
        pcb[i].turnAroundTime = pcb[i].completionTime;
        pcb[i].waitTime = pcb[i].turnAroundTime - pcb[i].burstTime;
        prevProcCompTime = pcb[i].completionTime;
        totalWaitTime += pcb[i].waitTime;
        totalTurnAroundTime += pcb[i].turnAroundTime;
    }

    //Diplay details of each process
    printf("\nPId \t Priority \t BurstTime \t StartTime \t CompletitionTime \t TurnAroundTime\t WaitTime");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%6d\t\t%6d\t\t%6d\t\t\t%6d\t\t\t%6d", pcb[i].id, pcb[i].Priority,
               pcb[i].burstTime, pcb[i].startTime, pcb[i].completionTime,
               pcb[i].turnAroundTime, pcb[i].waitTime);
    }
    
    avgWaitTime = (float)totalWaitTime / n;
    avgTurnAroundTime = (float)totalTurnAroundTime / n;
    printf("\nAverage Waiting time: %f", avgWaitTime);
    printf("\nAverage Turn Around Time: %f\n", avgTurnAroundTime);
    return 0;
}