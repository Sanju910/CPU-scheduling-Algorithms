#include<iostream>
#include<queue>
#include<stdio.h>
#include<map>
using namespace std;

int main(){
    int n;
    int sumt = 0, sumw = 0;
    map<int,bool>m;
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
    int tq;
    cout<<"Enter the time quantum";
    cin>>tq;
    queue<int>q;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(min>at[i]){
            min = at[i];
            time = i;
        }
    }
    burst_time[n] = INT_MAX;
    q.push(time);
    m[time] = true;
    time = min;
    int val;
    int complete = 0;
    while(complete<n) {
        if(q.size()!=0){
        smallest = q.front();
        if(burst_time[smallest]<=tq){
            sum_burst_time -= temp[smallest];
            printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time+1, time + 1 - temp[smallest] - at[smallest]);
            sumt += time + 1 - at[smallest];
            sumw += time + 1 - temp[smallest] - at[smallest];
            time += burst_time[smallest];
            complete++;
            q.pop();
        }

        else{
            burst_time[smallest] -= tq;
            time += tq;
        }

        for (i = 0; i < n; i++) {
            if (at[i] <= time)
                q.push(i);
        }

        if(burst_time[smallest]!=0){
            val = q.front();
            q.pop();
            q.push(val);
        }
        }

        else
            time++;
    }
    printf("\n\n average waiting time = %f", sumw * 1.0 / n);
    printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
}
