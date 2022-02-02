#include<bits/stdc++.h>
using namespace std;

int main(){
    int memory_size;
    cout<<"Enter the memory size\n";
    cin>>memory_size;
    int page_size;
    cout<<"Enter the page size\n";
    cin>>page_size;
    int no_of_pages=memory_size/page_size;
    cout<<"Total number of pages available in the memory "<<no_of_pages;
    cout<<"\n";
    int no_of_process;
    cout<<"Enter the number of process\n";
    cin>>no_of_process;
    int rempages=no_of_pages;
    int s[10],fn[10][20];
    for(int i=1;i<=no_of_process;i++){ 
        cout<<"Enter no. of pages required for process "<<i<<"\n";
        cin>>s[i];

        if(s[i]>rempages){
            cout<<"Memory is Full\n";
            break;
        }

        rempages-=s[i];

        cout<<"Enter pagetable for process "<<i<<"\n";

        for(int j=0;j<s[i];j++){
            cin>>fn[i][j];
        }
    }
        int x,y,offset;
        cout<<"Enter Logical Address to find Physical Address\n";
        cout<<"Enter process no. and pagenumber and offset\n";
        cin>>x>>y>>offset;
        int physical_address;
            physical_address=fn[x][y]*page_size+offset;
            cout<<"The Physical address is "<<physical_address;
       

    
}