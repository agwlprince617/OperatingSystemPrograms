#include<bits/stdc++.h>
using namespace std;

void firstFit(int block_size[],int process_size[],int total_blocks,int total_process){
    int allocation[total_process];
    memset(allocation,-1,sizeof(allocation));

    for(int i=0;i<total_process;i++){
        for(int j=0;j<total_blocks;j++){
            if(block_size[j]>=process_size[i]){
                allocation[i]=j;
                block_size[j]-=process_size[i];
                break;
            }
        }
    }

    cout<<"Process No"<<"\t\t"<<"Process Size"<<"\t\t"<<"Block No\n";

    for(int i=0;i<total_process;i++){
        cout<<i+1<<"\t\t"<<process_size[i]<<"\t\t";
        if(allocation[i]!=-1) cout<<allocation[i]+1<<"\n";
        else cout<<"Not Allocated\n";
    }
}


int main(){
    int block_size[]={300,50,200,350,70};
    int process_size[]={200,47,212,426,10};
    int total_blocks=sizeof(block_size)/sizeof(block_size[0]);
    int total_process=sizeof(process_size)/sizeof(process_size[0]);
    firstFit(block_size,process_size,total_blocks,total_process);
}