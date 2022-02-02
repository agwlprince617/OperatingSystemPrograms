#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes\n";
    cin>>n;
    int bt[20],wt[20],tat[20];
    float wtavg,tatavg;
    for(int i=0;i<n;i++){
        cout<<"Enter the burst time for process "<<i+1<<"\n";
        cin>>bt[i];
    }
    wt[0]=wtavg=0;
    tat[0]=tatavg=bt[0];
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    cout<<"Process"<<"\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t"<<"TAT\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<"\n";
    }
    cout<<"\nAverage Waiting Time "<<wtavg/n;
    cout<<"\nAverage Turn Around Time "<<tatavg/n;

}