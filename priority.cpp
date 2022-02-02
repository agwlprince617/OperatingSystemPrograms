#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes\n";
    cin>>n;
    int p[20],bt[20],wt[20],tat[20],priority[20];
    float wtavg,tatavg;
    for(int i=0;i<n;i++){
        p[i]=i;
        cout<<"Enter the burst time for process "<<i+1<<"\n";
        cin>>bt[i];
        cout<<"Enter the priority of the process "<<i+1<<"\n";
        cin>>priority[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(priority[i]>priority[j]){
                swap(p[i],p[j]);
                swap(bt[i],bt[j]);
                swap(priority[i],priority[j]);
            }
        }
    }

    wt[0]=wtavg=0;
    tat[0]=tatavg=bt[0];
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    cout<<"Process"<<"\t"<<"Priority"<<"\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t\t\t"<<"TAT\n";
    for(int i=0;i<n;i++){
        cout<<p[i]<<"\t"<<priority[i]<<"\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t\t\t"<<tat[i]<<"\n";
    }
    cout<<"\nAverage Waiting Time "<<wtavg/n;
    cout<<"\nAverage Turn Around Time "<<tatavg/n;

}