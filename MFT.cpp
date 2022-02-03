#include<bits/stdc++.h>
using namespace std;

int main(){
    int memory_size;
    cout<<"Enter the total memory available in bytes\n";
    cin>>memory_size;
    int block_size;
    cout<<"Enter the block size in bytes\n";
    cin>>block_size;
    int number_of_process;
    cout<<"Enter the number of processes\n";
    cin>>number_of_process;
    int memory_for_each_process[number_of_process];

    //Taking the memory required for each processes
    for(int i=0;i<number_of_process;i++){
        cout<<"Enter memory required for process "<<i+1<<"in bytes ";
        cin>>memory_for_each_process[i];
        cout<<"\n";
    }

    int number_of_blocks=memory_size/block_size;


    cout<<"Total number of blocks available in the memory "<<number_of_blocks;
    cout<<"\n";

    int p=0,i;
    int total_internal_fragmentation=0;
    for(i=0;i<number_of_process and p<number_of_blocks;i++){
        cout<<i+1<<"\t"<<memory_for_each_process[i];
        if(memory_for_each_process[i]>block_size){
            cout<<"\t\t"<<"No";
        }
        else{
             cout<<"\t\t"<<"Yes"<<"\t"<<block_size-memory_for_each_process[i];
             total_internal_fragmentation+=block_size-memory_for_each_process[i];
             p++;
        }
    }
    //For the remaining process

    if(i<number_of_process){
        cout<<"\n Memory is full,remaining process cannot be accomodated\n";
    }
    cout<<"Total Internal Fragmentation is "<<total_internal_fragmentation;


}