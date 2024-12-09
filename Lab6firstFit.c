#include <stdio.h>
#define MAX 25

void main()
{
    int frag[MAX], bSize[MAX], fSize[MAX]; // Fragmentation, block sizes, file sizes
    int bAlloc[MAX] = {0};                 // Block allocation flags
    int fAlloc[MAX];                       // File allocation indices
    int nB, nF, i, j, maxIdx;              // number of blocks and files, maxIdx = index of block of max size

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

    // First Fit Allocation
    // i represents fileNumber, j represents blockNumber or blockIndex
    for (i = 0; i < nF; i++)
    { // check, for every file i
        for (j = 0; j < nB; j++)
        { //  check every block j
            // If block j is unallocated and can fit the fileNo i
            if (!bAlloc[j] && bSize[j] >= fSize[i])
            {
                fAlloc[i] = j;                 // Allocate block j to file i
                frag[i] = bSize[j] - fSize[i]; // Calculate fragmentation
                bAlloc[j] = 1;                 // Mark block as allocated
                break;                         // Move to the next file
            }
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
}
