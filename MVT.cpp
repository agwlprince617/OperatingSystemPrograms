// Enter the total memory available (in Bytes) -- 1000 
// Enter memory required for process 1 (in Bytes) -- 400 
// Memory is allocated for Process 1 Do you want to continue(y/n) -- y 
// Enter memory required for process 2 (in Bytes) -- 275 
// Memory is allocated for Process 2
//  Do you want to continue(y/n) -- y 
 
//  Enter memory required for process 3 (in Bytes) -- 550
//   OUTPUT Memory is Full Total Memory Available -- 1000
//  PROCESS MEMORY ALLOCATED 
//  1 400 2 275 
//  Total Memory Allocated is 675
//  Total External Fragmentation is 325

#include<bits/stdc++.h>
using namespace std;

int main(){
    int memory_size;
    cout<<"Enter the total memory available in bytes\n";
    cin>>memory_size;

    int temp=memory_size;
    int i,p=0;
    char ch='y';
    int memory_for_each_process[10];
    for(i=0;ch=='y';i++){
        cout<<"Enter memory required for process "<<i+1<<"in bytes ";
        cin>>memory_for_each_process[i];
        if(memory_for_each_process[i]<=temp){
            cout<<"\nMemory is allocated for process "<<i+1;
            temp-=memory_for_each_process[i];
            p++;
        }
        else{
            cout<<"Memory is full\n";
            break;
        }
        cout<<"Do you want to continue (y/n) \n";
        cin>>ch;
    }
    cout<<"Total memory available is "<<memory_size;

    for(i=0;i<p;i++){
        cout<<"\n \t"<<i+1<<"\t\t"<<memory_for_each_process[i];
    }
    cout<<"\n";
    cout<<"Total memory allocated is "<<memory_size<<endl;
    cout<<"Total External Fragmentation is "<<temp;
}