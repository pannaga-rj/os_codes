#include <stdio.h>

void sort(int proc_id[], int at[], int bt[], int b[], int n) {
    int min, temp;
    for (int i = 0; i < n; i++) {
        min = at[i];
        for (int j = i; j < n; j++) {
            if (at[j] < min) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;

                temp = b[j];
                b[j] = b[i];
                b[i] = temp;

                temp = proc_id[i];
                proc_id[i] = proc_id[j];
                proc_id[j] = temp;
            }
        }
    }
}

int main() {
    int n, c = 0, t = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &t);

    int proc_id[n], at[n], bt[n], ct[n], tat[n], wt[n], b[n], rt[n], m[n];
    int f = -1, r = -1;
    int q[100];
    int count = 0;
    double avg_tat = 0.0, ttat = 0.0, avg_wt = 0.0, twt = 0.0;

    for (int i = 0; i < n; i++) {
        proc_id[i] = i + 1;
    }

    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        b[i] = bt[i];
        m[i] = 0;
        rt[i] = -1;
    }

    // sort based on AT
    sort(proc_id, at, bt, b, n);

    // Initialize queue
    f = r = 0;
    if (at[0] > 0) {
        c = at[0]; // Set current time to the arrival time of the first process if greater than 0
    }
    q[0] = proc_id[0]; // Add the first process to the queue
    m[0] = 1; // Mark the first process as started

    int p = 0, i = 0;

    while (f >= 0) {
        p = q[f++];
        i = 0;

        // Find the process index
        while (p != proc_id[i]) {
            i++;
        }

        // Execute the process
        if (b[i] >= t) { // Process burst time is greater than or equal to time quantum
            if (rt[i] == -1) {
                rt[i] = c; // Set response time
            }
            b[i] -= t; // Decrement burst time
            c += t; // Increment current time
        } else { // Process burst time is less than time quantum
            if (rt[i] == -1) {
                rt[i] = c; // Set response time
            }
            c += b[i]; // Increment current time by remaining burst time
            b[i] = 0; // Process is completed
        }

        // Add new processes to the queue
        for (int j = 0; j < n; j++) {
            if (at[j] <= c && proc_id[j] != p && m[j] != 1) {
                q[++r] = proc_id[j];
                m[j] = 1;
            }
        }

        // Check if process is completed
        if (b[i] == 0) {
            count++;
            ct[i] = c; // Set completion time
        } else {
            q[++r] = proc_id[i]; // Re-add process to the queue if not completed
        }

        // Re-initialize f = -1 when queue is empty
        if (f > r) {
            f = -1;
        }
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        rt[i] = rt[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output results
    printf("\nRRS scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", proc_id[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    // Calculate average turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        ttat += tat[i];
        twt += wt[i];
    }

    avg_tat = ttat / (double)n;
    avg_wt = twt / (double)n;

    printf("\nAverage turnaround time: %lfms\n", avg_tat);
    printf("\nAverage waiting time: %lfms\n", avg_wt);

    return 0;
}
