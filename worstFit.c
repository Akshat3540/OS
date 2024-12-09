#include <stdio.h>
#define MAX 25 // Max number of blocks or files

void main()
{
    int bSize[MAX], fSize[MAX], frag[MAX]; // Fragmentation, block sizes, file sizes
    int bAlloc[MAX] = {0}, fAlloc[MAX];    // Block allocation flags, file allocation indices
    int nB, nF, i, j, maxIdx; // number of blocks and files, maxIdx = index of block of max size

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

    // Memory allocation using Worst Fit
    for (i = 0; i < nF; i++) // For all files
    {
        maxIdx = -1; // Set the largest block index for each file
        for (j = 0; j < nB; j++) // For all blocks
            // Find the largest available block that fits the file
            // if (blockNotAllocated AND blockSize is big enough for the file AND (largestBlock not chosen OR currentBlockSize is larger than chosen block)
            if (!bAlloc[j] && bSize[j] >= fSize[i] && (maxIdx == -1 || bSize[j] > bSize[maxIdx]))
                maxIdx = j;
        if (maxIdx != -1)
        {                                       // If a suitable block is found
            bAlloc[maxIdx] = 1;                 // Mark block as allocated
            fAlloc[i] = maxIdx;                 // Assign block to file
            frag[i] = bSize[maxIdx] - fSize[i]; // Calculate fragmentation
        }
        else
        {
            fAlloc[i] = -1; // No block found for the file
            frag[i] = -1;
        }
    }

    // Output the results
    printf("\nFileNo\tFileSize\tBlockNo\tBlockSize\tFragment");
    for (i = 0; i < nF; i++)
    {
        if (fAlloc[i] != -1)
            printf("\n%d\t%d\t\t%d\t%d\t\t%d", i + 1, fSize[i], fAlloc[i] + 1, bSize[fAlloc[i]], frag[i]);
        else
            printf("\n%d\t%d\tNot Allocated\n\n", i + 1, fSize[i]);
    }
}
