#include<stdio.h>
int n;
struct Process_Table
{int process_no;int arr_time,burst_time,com_time,wait_time,tr_ar_time,p;int target;}p_table[100];
 
void Sorting()
{
	struct Process_Table p;
	int i,j;
	for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
				{
					if(p_table[i].arr_time > p_table[j].arr_time)
					{
						p = p_table[i];
						p_table[i] = p_table[j];
						p_table[j] = p;
					}
				}
			}
		}
int main()
{
	int i,t=0,b_t=0,bound;
	int a[10];
	float wait_time = 0, tr_ar_time = 0, avg_wait_time=0, avg_tr_ar_time=0;
	printf("Enter the Number of processes: ");
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		p_table[i].process_no = i+1;
		printf("\nEnter Details For P%d process:-\n", p_table[i].process_no);
		printf("Enter Arrival Time: ");
		scanf("%d", &p_table[i].arr_time );
		printf("Enter Burst Time:");
		scanf("%d", &p_table[i].burst_time);
		p_table[i].target = 0;
		b_t = b_t + p_table[i].burst_time;
	}
Sorting();
for(int i=0;i<n;i++)
{
a[i]=p_table[i].burst_time;
}
p_table[9].burst_time = 9999;
for(t = p_table[0].arr_time; t <= b_t+1;)
{
bound = 9;
for(i=0;i<n;i++)
{
if(p_table[i].arr_time <= t && p_table[i].burst_time < p_table[bound].burst_time && p_table[i].target != 1)
{
bound= i;
}
if(p_table[bound].burst_time==0 && p_table[i].target != 1)
{
p_table[i].target = 1;
p_table[bound].com_time=t;p_table[bound].burst_time=9999;
printf("P%d completes in %d\n",p_table[i].process_no,p_table[bound].com_time);
}
}
t++;
(p_table[bound].burst_time)--;
}
for(i=0;i<n;i++)
{
p_table[i].tr_ar_time=(p_table[i].com_time)-(p_table[i].arr_time);
avg_tr_ar_time=avg_tr_ar_time+p_table[i].tr_ar_time;
p_table[i].wait_time=((p_table[i].tr_ar_time)-a[i]);
avg_wait_time=avg_wait_time+p_table[i].wait_time;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p_table[i].process_no,p_table[i].arr_time,p_table[i].com_time,p_table[i].tr_ar_time
,p_table[i].wait_time);
 }
printf("Average Turn around Time: %f\t\n\n",avg_tr_ar_time);
printf("Average Waiting Time :\t %f\t\n",avg_wait_time);
}
