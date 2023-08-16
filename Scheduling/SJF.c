#include <stdio.h>
int main()
{
    int i,n,temp,x=0,cpu=0,t;
    float awt = 0.0, atat = 0.0;
    int pid[10], at[10], bt[10], wt[10], tat[10];
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    printf("Enter the process id, arrival time, and burst time of processes:\n");
    for(i=0; i<n; i++){
        scanf("%d%d%d", &pid[i],&at[i],&bt[i]);
    }
    printf("Processid\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while(x<n){
        temp=100;
        for(i=0;i<n;i++){
            if(at[i]<cpu && bt[i]>0){
                if(bt[i]<temp){
                    temp=bt[i];
                    t=i;
                }
            }
        }

        if(temp==100){
            cpu++;
            continue;
        }

        cpu=cpu+bt[t];
        tat[t]=cpu-at[t];
        wt[t]=tat[t]-bt[t];
        awt+=wt[t];
        atat+=tat[t];
        printf("\n%d\t%d\t%d\t%d\t%d", pid[t], at[t], bt[t], wt[t], tat[t]);
        bt[t]=0;
        x++;
    }
    awt = awt / n;
    atat = atat / n;
    printf("\navgwt:%f\navgtat:%f", awt, atat);
    return 0;
}