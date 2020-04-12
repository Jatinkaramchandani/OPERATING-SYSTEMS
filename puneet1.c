#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
       int arr_time[5]={0,0,0,0,0};//Arrival Time of the different processes, According to Question all the processe arrived at the same time.
       int burst_time[5];// CPU Burst Time, will be fetched form the file named cpuburst.txt 
       int com_time[5];// Completion time.
       int turn_ar_time[5];// Turn Around Time = Completion Time - Arrival Time.
       int wait_time[5];// Waiting time. Time a process will wait to get executed.
       float avg_wait_time=0; // Average waiting time for the five different process.
       float avg_turn_ar_time=0;// Average turn around time for the five different process.
       int n,fd;int i=0;char buffer[100];// Variables
       fd = open("cpuburst.txt",O_RDWR,0777);//Opening the file
       n= read(fd,buffer,10000000);//reading the file
       write(1,"\n Reading the file",18);
       for(i=0;i<100;i++){if(i%5==0){write(1,".",1);}}// Don't confuse it's printing dots only.
       write(1,"\n Validating the read Values from the file",42);
       for(i=0;i<n;i++){if(buffer[i]=='-'){write(1,"Error : The give number are negative",37);exit(0);}}// Validating, the file does not contain the negative values.
       write(1,"\n The first five values are  ",27);
       write(1,buffer,5);
       write(1,"\n Reading the CPU Burst for P1,P2,P3,P4,P5",42);for(i=0;i<100;i++){if(i%5==0){write(1,".",1);}}// Don't confuse it's printing dots(pattern) only.
       for(i=0;i<5;i++){printf("\n Enter the burst time of P");printf("%d\n",i);scanf("%d",&burst_time[i]);}// Explicit option to add the CPU burst, if don't want to give other CPU burst just input the five values shown above.
       for(int i = 0; i <5; ++i){for (int j = i + 1; j < 5; ++j){if (burst_time[i] > burst_time[j]){int a =  burst_time[i];burst_time[i] = burst_time[j];burst_time[j] = a;}}}// Arranging the processes according to the CPU busrt time to in ascending order to do the Shortest job first.
       for(i=0;i<5;i++){printf("%d",burst_time[i]);}
       write(1,"\n Calculating the waiting time",30);for(i=0;i<100;i++){if(i%5==0){write(1,".",1);}}//Calculating the Waiting time.
       for(i=0;i<5;i++){if(i==0){wait_time[i]=0;}else{wait_time[i]=wait_time[i-1]+burst_time[i-1];}}
       for(i=0;i<5;i++){printf("\n%d\n",wait_time[i]);}
       write(1,"\n Calculating the completion time",33);for(i=0;i<100;i++){if(i%5==0){write(1,".",1);}}// Completion time = Burst time + Wait time.
       for(i=0;i<5;i++){com_time[i]=burst_time[i]+wait_time[i];}
       for(i=0;i<5;i++){printf("\n%d\n",com_time[i]);}
       write(1,"\n Calculating the turn around time",34);for(i=0;i<100;i++){if(i%5==0){write(1,".",1);}}// Calculating the Turn Around Time.
       for(i=0;i<5;i++){turn_ar_time[i]=com_time[i]-arr_time[i];}
       for(i=0;i<5;i++){printf("\n%d\n",turn_ar_time[i]);}
       write(1,"\n Calculating the average turn around time",43);for(i=0;i<100;i++){if(i%5==0){write(1,".",1);}}
       for(i=0;i<5;i++){avg_turn_ar_time=avg_turn_ar_time+turn_ar_time[i];if(i==4){avg_turn_ar_time=avg_turn_ar_time/5;}}//Calcualting the average turn around time.
       printf("\n%f\n",avg_turn_ar_time);
       write(1,"\n Calculating the average waiting time",42);for(i=0;i<100;i++){if(i%5==0){write(1,".",1);}}
       for(i=0;i<5;i++){avg_wait_time=avg_wait_time+wait_time[i]; if(i==4){avg_wait_time=avg_wait_time/5;}}//Calculating the average Waiting time.
       printf("\n%f\n",avg_wait_time);    
}
