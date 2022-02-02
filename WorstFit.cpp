#include<bits/stdc++.h>
using namespace std;

void worstFit(int block_size[],int process_size[],int total_blocks,int total_process){
    int allocation[total_process];
    memset(allocation,-1,sizeof(allocation));

    for(int i=0;i<total_process;i++){
        int bestIdx=-1;
        for(int j=0;j<total_blocks;j++){
            if(block_size[j]>=process_size[i]){
               if(bestIdx==-1) bestIdx=j;
               else if(block_size[bestIdx]<block_size[j]) bestIdx=j;
            }
        }
        //If we found a block for current process
        if(bestIdx!=-1){
            allocation[i]=bestIdx;
            //Update the memory after allocation
            block_size[bestIdx]-=process_size[i];
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
    int block_size[]={100, 500, 200, 300, 600}; 
    int process_size[]={212, 417, 112, 426}; 
    int total_blocks=sizeof(block_size)/sizeof(block_size[0]);
    int total_process=sizeof(process_size)/sizeof(process_size[0]);
    worstFit(block_size,process_size,total_blocks,total_process);
}