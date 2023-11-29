#include <stdio.h>
#include <stdlib.h>

void fifo(int ref[], int size, int n) {
    int frames[n];
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }
    int pageMiss = 0;
    int pageHits = 0;
    int currentIndex = 0;

    for (int i = 0; i < size; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            pageHits++;
        } else {
            frames[currentIndex] = ref[i];
            currentIndex = (currentIndex + 1) % n; // current index value to next index in FIFO % no of frames
            pageMiss++;
        }
    }

    printf("FIFO Page Faults: %d, Page Hits: %d\n", pageMiss, pageHits);
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

    fifo(ref, size, frames);

    return 0;
}
