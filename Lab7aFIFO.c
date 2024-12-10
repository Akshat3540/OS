#include <stdio.h>
int frames[3];
void display()
{
    int i;
    printf("\n");
    for (i = 0; i < 3; i++)
        printf("%d\t", frames[i]);
}
void main()
{
    int i, j;
    int pages[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}; // Reference string
    int isPageInFrame = 0, isFrameAvailable = 0;
    int pageFaults = 0, frameCount = 3, nextReplaceIndex = 0;
    for (i = 0; i < frameCount; i++)
    {
        frames[i] = -1;
    }
    for (j = 0; j < 12; j++)
    {
        isPageInFrame = 0;
        isFrameAvailable = 0;
        for (i = 0; i < frameCount; i++)
        {
            if (frames[i] == pages[j])
            {
                isPageInFrame = 1;
                isFrameAvailable = 1;
                break;
            }
        }

        // If the page is not in a frame, check for an empty frame
        if (isPageInFrame == 0)
        {
            for (i = 0; i < frameCount; i++)
            {
                if (frames[i] == -1)
                {
                    frames[i] = pages[j];
                    isFrameAvailable = 1;
                    break;
                }
            }
        }

        if (isFrameAvailable == 0)
        {
            frames[nextReplaceIndex] = pages[j];
            nextReplaceIndex++;
            pageFaults++;
            if (nextReplaceIndex >= frameCount)
            {
                nextReplaceIndex = 0; // Reset to the first frame
            }
        }
        display();
    }
    printf("\nNumber of page faults: %d\n", pageFaults + frameCount);
}
