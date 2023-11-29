#include <stdio.h>
#include <stdlib.h>
struct process {
int arrivalTime;
int burstTime;
int completionTime;
int turnTime;
int waitingTime;
int startTime;
};
int main() {
int n, tq;
struct process p[50];
float avgWaiting;
int totalTurn = 0, burstArr[50];
float avgTurn;
int totalWaiting = 0, index;
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter time quantum of CPU: ");
scanf("%d", &tq);
for (int i = 0; i < n; i++) {
printf("Enter arrival time of process %d: ", i + 1);
scanf("%d", &p[i].arrivalTime);
printf("Enter burst time of process %d: ", i + 1);
scanf("%d", &p[i].burstTime);
burstArr[i] = p[i].burstTime;
printf("\n");
}
int q[100], front = 0, rear = -1;
int current_time = 0;
q[++rear] = 0;
int completed = 0;
int mark[100] = {0};
while (completed != n) {
index = q[front++];
if (burstArr[index] == p[index].burstTime) {
p[index].startTime = current_time > p[index].arrivalTime ? current_time : p[index].arrivalTime;
current_time = p[index].startTime;
}
if (0 < burstArr[index] - tq) {
burstArr[index] -= tq;
current_time += tq;
} else {

current_time += burstArr[index];
p[index].completionTime = current_time;
p[index].turnTime = p[index].completionTime - p[index].arrivalTime;
p[index].waitingTime = p[index].turnTime - p[index].burstTime;
totalWaiting += p[index].waitingTime;
totalTurn += p[index].turnTime;
completed++;
burstArr[index] = 0;
}
for (int i = 1; i < n; i++) {
if (burstArr[i] > 0 && p[i].arrivalTime <= current_time && !mark[i]) {
mark[i] = 1;
q[++rear] = i;
}
}
if (0 < burstArr[index]) {
q[++rear] = index;
}
if (front > rear) {
for (int i = 1; i < n; i++) {
if (0 < burstArr[i]) {
mark[i] = 1;
q[++rear] = i;
break;
}
}
}
}
avgWaiting = (float) totalWaiting / n;
avgTurn = (float) totalTurn / n;
printf("\n");
printf("Average Waiting Time = %.2f\n", avgWaiting);
printf("Average Turnaround Time = %.2f\n", avgTurn);

printf("\n");
printf("Process\tAT\tBT\tCT\tWT\tTAT\n");
for (int i = 0; i < n; i++) {
printf("%d\t%d\t%d\t%d\t%d\t%d\n",
i + 1,
p[i].arrivalTime,
p[i].burstTime,
p[i].completionTime,
p[i].waitingTime,
p[i].turnTime);
}
return 0;
}
