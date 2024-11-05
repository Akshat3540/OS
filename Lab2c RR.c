#include <stdio.h>
struct processControlBlock
{
    int id;
    int burstTime;
    int startTime, completionTime, waitTime, turnAroundTime;
} pcb[20] = {0};
int main()
{
    int i, n, GanttChart = 0; // GanttChart keeps track of the current time
    int QuantumTime;
    int totalWaitTime = 0, totalTurnAroundTime = 0;
    float avgWaitTime, avgTurnAroundTime;
    // Input process data
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter Quantum Time: ");
    scanf("%d", &QuantumTime);
    printf("Enter Process ID and Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &pcb[i].id, &pcb[i].burstTime);
        pcb[i].startTime = -1; // Initialize start time to -1 to track first start
    }
    // Temporary array to store remaining burst time for each process
    int remainingBurstTime[20];
    for (i = 0; i < n; i++)
    {
        remainingBurstTime[i] = pcb[i].burstTime;
    }
    int allProcessesCompleted = 0; // Flag to check if all processes are completed
    while (!allProcessesCompleted)
    {
        allProcessesCompleted = 1; // Assume all processes are complete at the beginning of each cycle 
        for (i = 0; i < n; i++)
        {
            if (remainingBurstTime[i] > 0)
            {                              // Process still has burst time left
                allProcessesCompleted = 0; // At least one process needs more time
                // Record the start time for the process the first time it starts
                if (pcb[i].startTime == -1)
                {
                    pcb[i].startTime = GanttChart;
                }
                // Process executes for either Quantum Time or remaining burst time, whichever is smaller 
                if (remainingBurstTime[i] >= QuantumTime)
                {
                    GanttChart += QuantumTime;
                    remainingBurstTime[i] -= QuantumTime;
                }
                else
                {
                    GanttChart += remainingBurstTime[i];
                    remainingBurstTime[i] = 0;
                }
                // If process is completed, set its completion time
                if (remainingBurstTime[i] == 0)
                {
                    pcb[i].completionTime = GanttChart;
                }
            }
        }
    }
    // Calculate turn-around and wait times for each process
    for (i = 0; i < n; i++)
    {
        pcb[i].turnAroundTime = pcb[i].completionTime;
        pcb[i].waitTime = pcb[i].turnAroundTime - pcb[i].burstTime;
        totalWaitTime += pcb[i].waitTime;
        totalTurnAroundTime += pcb[i].turnAroundTime;
    }
    // Display process information
    printf("\nProcess ID\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitTime");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t\t%6d\t\t%6d\t\t%6d\t\t%6d",
               pcb[i].id, pcb[i].burstTime, pcb[i].completionTime, pcb[i].turnAroundTime,
               pcb[i].waitTime);
    }
    // Calculate and display average waiting time and turn-around time
    avgWaitTime = (float)totalWaitTime / n;
    avgTurnAroundTime = (float)totalTurnAroundTime / n;
    printf("\n\nAverage Waiting Time: %.2f", avgWaitTime);
    printf("\nAverage Turn Around Time: %.2f\n", avgTurnAroundTime);
    return 0;
}
