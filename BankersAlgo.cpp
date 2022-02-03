#include<bits/stdc++.h>
using namespace std;

int main(){
    int allocated[10][10],maxneed[10][10],need[10][10];
    int p,r;
    cout<<"Enter the number of process\n";
    cin>>p;
    cout<<"Enter the number of resources\n";
    cin>>r;
    cout<<"Enter allocation matrix\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>allocated[i][j];
        }
    }
    cout<<"Enter maxneed matrix\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>maxneed[i][j];
        }
    }
     cout<<"The need matrix\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j]=maxneed[i][j]-allocated[i][j];
            cout<<need[i][j];
        }
        cout<<"\n";
    }
    
    int available[r];
    cout<<"Enter available resources of each type\n";
    for(int i=0;i<r;i++){
        cin>>available[i];
    }
    

    int visited[p],ans[p],index=0;

    for(int i=0;i<p;i++){
        visited[i]=0;
    }
    

    for(int k=0;k<p;k++){
        for(int i=0;i<p;i++){
            if(visited[i]==0){
                int flag=0;
                for(int j=0;j<r;j++){
                    if(need[i][j]>available[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[index++]=i;
                    for(int j=0;j<r;j++){
                        available[j]+=allocated[i][j];
                    }
                    visited[i]=1;
                }
            }
        }
    }
    int flag=1;
    for(int i=0;i<p;i++){
        if(!visited[i]){
            flag=0;
            cout<<"System is in unsafe state\n";
            break;
        }
    }
    if(flag==1){
        cout<<"System is in safe state and order of the execution is\n";
        for(int i=0;i<p;i++){
            cout<<ans[i]<<" ";
        }
    }
}