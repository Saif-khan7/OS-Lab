#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void calculateTimes(struct Process proc[], int n, int time_quantum) {
    int time = 0; // Current time
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    while (1) {
        int done = 1; // Flag to check if all processes are done

        // Iterate through processes
        for (int i = 0; i <n; i++) {
            if (proc[i].remaining_burst_time > 0) {
                done = 0; // There is still at least one process to execute

                // Execute the process for the time quantum or its remaining burst time, whichever is smaller
                int execution_time = (proc[i].remaining_burst_time < time_quantum) ? proc[i].remaining_burst_time : time_quantum;
                time += execution_time;
                proc[i].remaining_burst_time -= execution_time;

                // Update completion time, turnaround time, and waiting time
                if (proc[i].remaining_burst_time == 0) {
                    proc[i].completion_time = time;
                    proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;
                    proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;

                    total_turnaround_time += proc[i].turnaround_time;
                    total_waiting_time += proc[i].waiting_time;
                }
            }
        }

        if (done)
            break;
    }

    // Calculate and print averages
    float average_turnaround_time = (float)total_turnaround_time / n;
    float average_waiting_time = (float)total_waiting_time / n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].id, proc[i].arrival_time, proc[i].burst_time,proc[i].completion_time, proc[i].turnaround_time, proc[i].waiting_time);
    }

    printf("\nAverage Turnaround Time: %f\n", average_turnaround_time);
    printf("Average Waiting Time: %f\n", average_waiting_time);
}

int main() {
    int n;
    int time_quantum;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    // Declare an array of processes
    struct Process proc[n];

    // Input details for each process
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &proc[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
        proc[i].remaining_burst_time = proc[i].burst_time;
    }

    // Calculate and print process details and averages
    calculateTimes(proc, n, time_quantum);

    return 0;
}
