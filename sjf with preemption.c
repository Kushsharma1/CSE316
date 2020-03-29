#include<stdio.h>
int n;
struct process
{
    int Process_no;
    int p,ct,Arrival_Time,Burst_Time,Wait_Time,Turnaround_Time;
    int flag;
}

p_list[100];
void Sorting()
{
    struct process p;
    int i, j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p_list[i].Arrival_Time > p_list[j].Arrival_Time)
            {
                p = p_list[i];
                p_list[i] = p_list[j];
                p_list[j] = p;
            }
		}
    }
}

int main()
{
    int i,t=0,b_t=0,peak;
    int a[10];
    float Wait_Timeime = 0, Turnaround_Time = 0, avg_w_t=0, avg_Turnaround_Time=0;
    printf("Enter the no. of processes: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        p_list[i].Process_no = i+1;
        printf("\nEnter Details For P%d process:-\n", p_list[i].Process_no);
		printf("Enter Arrival Time: ");
		scanf("%d", &p_list[i].Arrival_Time );
		printf("Enter Burst Time: ");
		scanf("%d", &p_list[i].Burst_Time);
		p_list[i].flag = 0;
		b_t = b_t + p_list[i].Burst_Time;
}

Sorting();
for(i=0;i<n;i++)
{
    a[i]=p_list[i].Burst_Time;
}
p_list[9].Burst_Time = 9999;
for(t = p_list[0].Arrival_Time; t <= b_t+1;)
{
    peak = 9;
    for(i=0;i<n;i++)
    {
		if(p_list[i].Arrival_Time <= t && p_list[i].Burst_Time < p_list[peak].Burst_Time && p_list[i].flag != 1)
		{
			peak = i;
		}
		if(p_list[peak].Burst_Time==0 && p_list[i].flag != 1)
		{
			p_list[i].flag = 1;
			p_list[peak].ct=t;p_list[peak].Burst_Time=9999;
			printf("P%d completes in %d\n",p_list[i].Process_no,p_list[peak].ct);
		}
	}
	t++;
	(p_list[peak].Burst_Time)--;
}
for(i=0;i<n;i++)
{
	p_list[i].Turnaround_Time=(p_list[i].ct)-(p_list[i].Arrival_Time);
	avg_Turnaround_Time=avg_Turnaround_Time+p_list[i].Turnaround_Time;
	p_list[i].Wait_Time=((p_list[i].Turnaround_Time)-a[i]);
	avg_w_t=avg_w_t+p_list[i].Wait_Time;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
	printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].Process_no,p_list[i].Arrival_Time,p_list[i].ct,p_list[i].Turnaround_Time,p_list[i].Wait_Time);
}
printf("Average Turn around Time: %f\t\n\n",avg_Turnaround_Time);
printf("Average Waiting Time :\t %f\t\n",avg_w_t);

return 0;
}
