#include <stdio.h>
#include <limits.h>

int main() {
  int n;
  int sumt = 0, sumw = 0;
  printf("enter the no of processes : ");
  scanf("%d", & n);
  int time, burst_time[n+1], temp[n], at[n], sum_burst_time = 0, smallest, i;
  for (i = 0; i < n; i++) {
    printf("the arrival time for process P%d : ", i + 1);
    scanf("%d", & at[i]);
    printf("the burst time for process P%d : ", i + 1);
    scanf("%d", & burst_time[i]);
    sum_burst_time += burst_time[i];
    temp[i] = burst_time[i];
  }
  int min=INT_MAX;
  for(int i=0;i<n;i++){
    if(min>at[i])
        min = at[i];
  }
  burst_time[n] = INT_MAX;
  int count = 0;
  for (time = min; sum_burst_time > 0;) {
  smallest = n;
  for (i = 0; i < n; i++) {
    if (at[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
      smallest = i;
  }

  // Decrement the remaining burst time of the smallest process
  burst_time[smallest]--;

  // If the remaining burst time of the smallest process becomes 0, update the time and mark the process as completed
  if (burst_time[smallest] == 0) {
    sum_burst_time -= temp[smallest];
    printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + 1 - at[smallest], time + 1 - temp[smallest] - at[smallest]);
    sumt += time + 1 - at[smallest];
    sumw += time + 1 - temp[smallest] - at[smallest];
    burst_time[smallest] = INT_MAX;
  }

  time++;
}
  printf("\n\n average waiting time = %f", sumw * 1.0 / n);
  printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
  return 0;
}
