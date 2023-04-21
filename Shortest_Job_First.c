#include <stdio.h>
#include <limits.h>

int main() {
  int n;
  int sumt = 0, sumw = 0;
  printf("enter the no of processes : ");
  scanf("%d", &n);
  int time, burst_time[n+1], at[n], sum_burst_time = 0, smallest, i;
  for (i = 0; i < n; i++) {
    printf("the arrival time for process P%d : ", i + 1);
    scanf("%d", & at[i]);
    printf("the burst time for process P%d : ", i + 1);
    scanf("%d", & burst_time[i]);
    sum_burst_time += burst_time[i];
  }
  int min=INT_MAX;
  for(int i=0;i<n;i++){
    if(min>at[i])
        min = at[i];
  }
  burst_time[n] = INT_MAX;
  for (time = min; time < sum_burst_time;) {
    smallest = n;
    for (i = 0; i < n; i++) {
      if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest])
        smallest = i;
    }
    printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + burst_time[smallest] - at[smallest], time - at[smallest]);
    sumt += time + burst_time[smallest] - at[smallest];
    sumw += time - at[smallest];
    time += burst_time[smallest];
    burst_time[smallest] = INT_MAX;
  }
  printf("\n\n average waiting time = %f", sumw * 1.0 / n);
  printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
  return 0;
}
