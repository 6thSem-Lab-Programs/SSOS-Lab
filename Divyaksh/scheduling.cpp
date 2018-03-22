#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#define INT_MAX 9999

using namespace std;

typedef struct PROCESS {
  int id;
  int bt;
  int art;
  int wt;
  int tat;
}Process;

void schedulesrtf(Process *proc, int n) {
  vector<int> exe_id;
  int *rt = (int *)(calloc(n, sizeof(int)));
  int i;
  for (i = 0; i < n; i++)
    rt[i] = proc[i].bt;
  int complete = 0, t = 0, minm = INT_MAX;
  int shortest = 0, finish_time, total_wt = 0, total_tat = 0;
  int check = 0;

  while(complete != n) {
    // Find process with minimum remaining time, given that the job has arrived untill that time period
    check = 0;
    minm = INT_MAX;
    for (i = 0; i < n; i++) {
      if(proc[i].art <= t && rt[i] < minm && rt[i] > 0) {
        minm = rt[i];
        shortest = i;
        check = 1;
      }
    }

    if(check == 0) {
      t++;
      // printf("(complete, t)=>(%d,%d)\n", complete, t);
      continue;
    }

    rt[shortest]--;
    if(exe_id.empty() || exe_id.back()!=proc[shortest].id) {
      exe_id.push_back(proc[shortest].id);
    }

    if(rt[shortest] == 0) {
      complete++;
      finish_time = t+1;
      proc[shortest].wt = finish_time - proc[shortest].bt - proc[shortest].art;
      if(proc[shortest].wt < 0)
        proc[shortest].wt = 0;
    }
    t++;
    // printf("(complete, t)=>(%d,%d)\n", complete, t);
  }

  // Calculating Turnaround time
  for (i = 0; i < n; i++) {
    proc[i].tat = proc[i].wt + proc[i].bt;
  }

  // Printing the required data
  printf("\t\tSHORTEST REMAINING TIME FIRST\n");
  printf("%3s%16s%16s%16s%16s\n", "ID", "Burst Time", "Arrival Time", "Waiting Time", "Turnaround Time");
  for(i = 0; i < n; i++) {
    total_wt += proc[i].wt;
    total_tat += proc[i].tat;
    printf("%3d%16d%16d%16d%16d\n", proc[i].id, proc[i].bt, proc[i].art, proc[i].wt, proc[i].tat);
  }
  printf("\nThe execution order is:\n");
  for(i = 0; i < exe_id.size(); i++) {
    cout<<exe_id[i]<<",";
  }
  printf("\nAverage waiting time: %.3f\n", (float)(total_wt/n) );
  printf("Average Turnaround time: %.3f\n\n", (float)(total_tat/n) );
}

void schedulerr(Process *proc, int n, int quantum) {
  vector<int> exe_id;
  int *rt = (int *)(calloc(n, sizeof(int)));
  int i, t = 0, done = 0, total_wt = 0, total_tat = 0;

  for(i = 0; i < n; i++) {
    rt[i] = proc[i].bt;
  }
  t = proc[0].art;

  while(!done) {
    // printf("Entering loop\n" );
    done = 1;
    for(i = 0; i < n; i++) {
      if(rt[i] > 0 && proc[i].art <= t) {
        done = 0;
        if(rt[i] > quantum) {
          t+=quantum;
          rt[i] -= quantum;
          // printf("(t)=>(%d)\n",t );
          exe_id.push_back(proc[i].id);
        }
        else {
          t += rt[i];
          proc[i].wt = t - proc[i].art;
          rt[i] = 0;
          // printf("(t, wt)=>(%d, %d)\n",t, proc[i].wt );
          exe_id.push_back(proc[i].id);

        }
      }
    }
  }

  for(i = 0; i < n; i++) {
    proc[i].tat = proc[i].wt + quantum;
  }

  printf("\t\tROUND ROBIN\n");
  printf("%3s%16s%16s%16s%16s\n", "ID", "Burst Time", "Arrival Time", "Waiting Time", "Turnaround Time");
  for(i = 0; i < n; i++) {
    total_wt += proc[i].wt;
    total_tat += proc[i].tat;
    printf("%3d%16d%16d%16d%16d\n", proc[i].id, proc[i].bt, proc[i].art, proc[i].wt, proc[i].tat);
  }

  printf("\nThe execution order is:\n");
  for(i = 0; i < exe_id.size(); i++) {
    cout<<exe_id[i]<<",";
  }
  printf("\nAverage waiting time: %.3f\n", (float)(total_wt/n) );
  printf("Average Turnaround time: %.3f\n\n", (float)(total_tat/n) );

}

int main() {
  int n;
  // printf("Enter the number of processes:" );
  // scanf("%d", &n);
  // Process *proc = (Process *)(calloc(n, sizeof(Process)));
  Process proc[] = { { 1, 6, 1, 0, 0 }, { 2, 8, 1, 0, 0 },
                    { 3, 7, 2, 0, 0 }, { 4, 3, 3, 0, 0 } };
  n = 4;

  schedulesrtf(proc, n);
  schedulerr(proc, n, 2);
}
