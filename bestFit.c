#include <stdio.h>
#define MAX 25

int main()
{
    int bSize[MAX], fSize[MAX], frag[MAX];
    int bAlloc[MAX] = {0}, fAlloc[MAX];
    int nB, nF, i, j, minIdx, temp;

    // Input for number of blocks and files
    printf("Number of Blocks: ");
    scanf("%d", &nB);
    printf("Number of Files: ");
    scanf("%d", &nF);

    // Input sizes of blocks
    printf("Block Sizes: ");
    for (i = 0; i < nB; i++)
    {
        scanf("%d", &bSize[i]);
    }

    // Input sizes of files
    printf("File Sizes: ");
    for (i = 0; i < nF; i++)
    {
        scanf("%d", &fSize[i]);
    }
    // Best Fit Allocation
    for (i = 0; i < nF; i++) // for every file i
    {   
        fAlloc[i] = -1;
        minIdx = -1; // Reset for each file
        for (j = 0; j < nB; j++) // for every block j
        {
            if (!bAlloc[j] && bSize[j] >= fSize[i])
            {
                temp = bSize[j] - fSize[i]; // Calculate leftover space
                if (minIdx == -1 || temp < (bSize[minIdx] - fSize[i]))
                {
                    minIdx = j; // Track block with least leftover space
                }
            }
        }
        if (minIdx != -1)
        {
            fAlloc[i] = minIdx;                 // Allocate best-fitting block
            frag[i] = bSize[minIdx] - fSize[i]; // Calculate fragmentation
            bAlloc[minIdx] = 1;                 // Mark block as allocated
        }
        else
        {
            fAlloc[i] = -1;
            frag[i] = -1;
        }
    }

    // Output results
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 0; i < nF; i++)
    {
        if (fAlloc[i] != -1)
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, fSize[i], fAlloc[i] + 1, bSize[fAlloc[i]], frag[i]);
        else
            printf("\n%d\t%d\tNot Allocated", i + 1, fSize[i]);
    }
    return 0;
}
