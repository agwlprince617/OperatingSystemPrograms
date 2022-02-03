#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes\n";
    cin>>n;
    int p[20],bt[20],wt[20],tat[20],su[20];
    float wtavg,tatavg;
    for(int i=0;i<n;i++){
        p[i]=i;
        cout<<"Enter the burst time for process "<<i+1<<"\n";
        cin>>bt[i];
        cout<<"Enter the system/user of the process (0/1)?"<<i+1<<"\n";
        cin>>su[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(su[i]>su[j]){
                swap(p[i],p[j]);
                swap(bt[i],bt[j]);
                swap(su[i],su[j]);
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
    cout<<"Process"<<"\t"<<"System/User"<<"\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t\t\t"<<"TAT\n";
    for(int i=0;i<n;i++){
        cout<<p[i]<<"\t"<<su[i]<<"\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t\t\t"<<tat[i]<<"\n";
    }
    cout<<"\nAverage Waiting Time "<<wtavg/n;
    cout<<"\nAverage Turn Around Time "<<tatavg/n;

}