#include <stdio.h>
#include <stdlib.h>

// Function to sort the request array in ascending order
void sortRequests(int requests[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, head, seekTime = 0;
    
    printf("Enter the number of disk I/O requests: ");
    scanf("%d", &n);
    
    int requests[n];
    
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    sortRequests(requests, n);  // Sort the request array in ascending order
    
    // Find the index where the head is located
    int currentIndex = 0;
    while (currentIndex < n && requests[currentIndex] <= head) {
        currentIndex++;
    }
    
    printf("Order of execution: ");
    
    // C-SCAN goes to the end of the disk in one direction, then returns in the other direction
    // First, it goes in the increasing order
    for (int i = currentIndex; i < n; i++) {
        printf("%d -> ", requests[i]);
        seekTime += abs(requests[i] - head);
        head = requests[i];
    }
    
    // Then, it goes to the end of the disk in the opposite direction
    if (currentIndex < n) {
        seekTime += abs(0 - head); // Move the head to the beginning of the disk
        head = 0;
        for (int i = 0; i < currentIndex; i++) {
            printf("%d -> ", requests[i]);
            seekTime += abs(requests[i] - head);
            head = requests[i];
        }
    }
    
    printf("\n");
    
    printf("Total seek time: %d\n", seekTime);
    
    return 0;
}
