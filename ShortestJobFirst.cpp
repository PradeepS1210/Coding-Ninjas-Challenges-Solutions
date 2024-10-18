// Companies asking this question: Flipkart

/**************************************************************************************
Problem statement
You have to implement the shortest job first scheduling algorithm.

Shortest Job First is an algorithm in which the process having the smallest execution(burst) time is chosen for the next execution. Here, you will implement a non - preemptive version (a process will wait till process(es) with shorter burst time executes). You have to return the average waiting for the given number of processes.

Completion Time: Time at which process completes its execution.

Example:

SJF will schedule the job which is having least burst time.

Hence, Average waiting time = (5 + 0 + 2) / 3 = 2.33

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
0 3
0 1
0 2
Sample Output 1 :
1.33
Explanation For Sample Input 1:
The table for the given number of processes is 

Therefore, the average waiting for the given process is 1.33.
Sample Input 2 :
2
1 4
1 3
Sample Output 2 :
1.50
Constraints:
1 <= N <= 10^2
1 <= at, bt <= 10^3

Where 'N' denotes the number of processes, 'at' and 'bt' represents the arrival time and burst time of any process.

Time Limit: 1 sec.
**************************************************************************************/

struct Process {
    int arrivalTime;
    int burstTime;
    int index;
};

float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) {
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i] = {arrivalTime[i], burstTime[i], i};
    }
    
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    vector<int> waitingTime(n, 0);
    int completed = 0;
    vector<bool> isCompleted(n, false);

    while (completed < n) {
        int idx = -1;
        int minBurstTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !isCompleted[i]) {
                if (processes[i].burstTime < minBurstTime) {
                    minBurstTime = processes[i].burstTime;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            currentTime += processes[idx].burstTime;
            waitingTime[processes[idx].index] = currentTime - processes[idx].arrivalTime - processes[idx].burstTime;
            isCompleted[idx] = true;
            completed++;
        } else {
            currentTime++;
        }
    }

    float totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
    }

    return totalWaitingTime / n;
}
