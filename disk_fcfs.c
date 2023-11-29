#include <stdio.h>
#include <stdlib.h>
int main() {
int n, head, seekTime = 0;
printf("Enter the number of disk I/O requests: ");
scanf("%d", &n);
int requests[n];
printf("Enter the requests in order: ");
for (int i = 0; i < n; i++) {
scanf("%d", &requests[i]);
}
printf("Enter the initial head position: ");
scanf("%d", &head);
printf("Order of execution: ");
for (int i = 0; i < n; i++) {
printf("%d -> ", requests[i]);
seekTime += abs(requests[i] - head);
head = requests[i];
}
printf("\nTotal seek time: %d\n", seekTime);
return 0;
}
