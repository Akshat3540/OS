#include <stdio.h>
int frames[3];
void display()
{
    for (int i = 0; i < 3; i++)
        printf("%d\t", frames[i]);
    printf("\n");
}

void main()
{
    int page[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int lastUsed[3] = {0, 0, 0};
    int pageFaults = 0, time = 0;
    for (int i = 0; i < 3; i++)
        frames[i] = -1;
    for (int j = 0; j < 12; j++)
    {
        int isPageInFrame = 0;
        for (int i = 0; i < 3; i++)
        {
            if (frames[i] == page[j])
            {
                isPageInFrame = 1;
                lastUsed[i] = time;
                break;
            }
        }

        if (!isPageInFrame)
        {
            int isFrameAvailable = 0;

            for (int i = 0; i < 3; i++)
            {
                if (frames[i] == -1)
                {
                    frames[i] = page[j];
                    lastUsed[i] = time;
                    isFrameAvailable = 1;
                    pageFaults++;
                    break;
                }
            }

            if (!isFrameAvailable)
            {
                int leastRecentlyUsedIndex = 0;
                for (int i = 1; i < 3; i++)
                {
                    if (lastUsed[i] < lastUsed[leastRecentlyUsedIndex])
                    {
                        leastRecentlyUsedIndex = i;
                    }
                }
                frames[leastRecentlyUsedIndex] = page[j];
                lastUsed[leastRecentlyUsedIndex] = time;
                pageFaults++;
            }
        }
        time++;
        display();
    }
    printf("\nNumber of page faults: %d", pageFaults);
}
