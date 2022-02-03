#include<stdio.h>

int main()
{

      //Initialisation and data gathering from user.
      int i, processes, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &processes);
      x = processes;
      for(i = 0; i < processes; i++)
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);

            printf("Arrival Time:\t");

            scanf("%d", &arrival_time[i]);

            printf("Burst Time:\t");

            scanf("%d", &burst_time[i]);

            temp[i] = burst_time[i];              // storing burst time in a temp array so it can be changed
      }

      printf("\nEnter Time Quantum:\t");
      scanf("%d", &time_quantum);


      //Logic
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n"); //total is total time till that instance
      for(total = 0, i = 0; x != 0;)       //i is process count right now...we go in merry go rounds
      {                                     // when each process has burst time reamining equal to 0 its x
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i]; //adding to total time here
                  temp[i] = 0;            //since temp[i] in this case will be less than Quantum so all of it will be added and temp[i] will be 0
                  counter = 1;            // used as a flag variable for this condition.
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;   //simple case adding quantum
            }
            if(temp[i] == 0 && counter == 1)   //if one process finishes...then printing all its contents.
            {                                  //the processes which will finsih first, will be printed first.
                  x--;   //till processes are not equal to 0, loop runs
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i],total - arrival_time[i],total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];  //total wait time
                  turnaround_time = turnaround_time + total - arrival_time[i];      //total turnaround time
                  counter = 0;  // because temp[i] will be 0 but the counter is set to 0, which prevents printing repetition
            }
            if(i == processes - 1)    //this is the last process in queue so to prevent overflow.
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total) //the next process will only be considered if the total time is less than the arrival time of next process
            {
                  i++;
            }
            else      //if it is not equal or less than total time then we continue with same process
            {
                  i = 0;
            }
      }

      //Calculation
      average_wait_time = wait_time * 1.0 / processes;
      average_turnaround_time = turnaround_time * 1.0 / processes;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;
}
