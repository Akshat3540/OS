#include <stdio.h>
void main()
{
    int work[10], available[10], allocation[10][10], need[10][10];
    int max[10][10], processCount, resourceCount;
    int i, j, k, safeSequence[10], finishCount = 0;
    char finish[10] = {'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f'};

    // Input No. of Processes and No. of Resource types
    printf("\nEnter the number of processes: ");
    scanf("%d", &processCount);
    printf("\nEnter the number of resources: ");
    scanf("%d", &resourceCount);

    printf("\nEnter the total number of resources for each type:\n");
    // Input loop for number of AVAILABLE Resources
    for (i = 1; i <= resourceCount; i++)
    {
        scanf("%d", &available[i]);
    }

    printf("\nEnter the maximum resources required by each process:\n");
    // Input loop for MAX Matrix
    for (i = 1; i <= processCount; i++)
    {
        for (j = 1; j <= resourceCount; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the allocated resources for each process:\n");
    // Input loop for ALLOCATION Matrix
    for (i = 1; i <= processCount; i++)
    {
        for (j = 1; j <= resourceCount; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Loop to calculate the NEED Matrix
    for (i = 1; i <= processCount; i++)
    {
        for (j = 1; j <= resourceCount; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize WORK Array with available resources
    for (i = 1; i <= resourceCount; i++)
    {
        work[i] = available[i];
    }

    // k loop: Checking for a safe sequence
    for (k = 1; k <= processCount; k++)
    {   //i loop: Checking for unfinished processes
        for (i = 1; i <= processCount; i++)
        {   
            int resourceMet = 0;//Setting resourceMet for the current process 'i' to 0 initially
            if (finish[i] == 'f')//if(Any Process 'i' Is Unfinished)
            {   //j loop: Checking if unfinished process# 'i' has enough resources to be executed
                for (j = 1; j <= resourceCount; j++)
                {
                    if (need[i][j] <= work[j])
                    {
                        resourceMet++;
                    }
                }
                if (resourceMet == resourceCount)//if(Required Needs for the Process can be met)
                { // Simulate the execution of the Respective Process
                    for (j = 1; j <= resourceCount; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 't';//Setting respective Process no. status as finished, finish[process#]=true
                    safeSequence[k] = i;//Feeding Finished Process no. in the safe sequence after execution
                    finishCount++;//Updating the number of finished processes
                    break;
                }
            }
        }
    }

    // Printing Results
    if (finishCount == processCount) // if(All processes finished)
    {
        printf("\nThe system is in a safe state.\nSafe sequence: ");
        // Loop to print the safe sequence
        for (i = 1; i <= processCount; i++)
        {
            printf("%d ", safeSequence[i]);
        }
    }
    else
    {
        printf("\nThe system is not in a safe state.");
    }
}
