#include <stdio.h>
#include <stdlib.h>

void lru(int ref[], int size, int n) {
    int frames[n];
    int time[n];
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
        time[i] = 0;
    }
    int pageMiss = 0;
    int pageHits = 0;

    for (int i = 0; i < size; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == ref[i]) {
                flag = 1;
                time[j] = i;
                break;
            }
        }

        if (flag == 1) {
            pageHits++;
        } else {
            int oldest = 0;
            for (int j = 0; j < n; j++) {
                if (time[j] < time[oldest]) {
                    oldest = j;
                }
            }
            frames[oldest] = ref[i];
            time[oldest] = i;
            pageMiss++;
        }
    }

    printf("LRU Page Faults: %d, Page Hits: %d\n", pageMiss, pageHits);
}

int main(void) {
    int frames;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int size;
    printf("Enter the size of the reference string: ");
    scanf("%d", &size);

    int ref[size];
    printf("Enter the reference string: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &ref[i]);
    }

    lru(ref, size, frames);

    return 0;
}
