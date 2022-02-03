#include<stdio.h>
int loc(int time[],int fs){
    int mini=time[0];
    int pos=0;
    for(int i=1;i<fs;i++){
        if(time[i]<mini){
            mini=time[i];
            pos=i;
        }
    }
    return pos;
}
int main(){
    int page[20],time[20],f[20],ps,fs;
    printf("Enter the size of pages\n");
    scanf("%d",&ps);
    printf("Enter the size of frames\n");
    scanf("%d",&fs);
    printf("Enter the number of pages\n");
    for(int i=0;i<ps;i++){
        scanf("%d",&page[i]);
    }
    
    for(int i=0;i<fs;i++){
        f[i]=0;
    }
    int page_fault=0,count=0;

    for(int i=0;i<fs;i++){
        f[i]=page[i];
        page_fault++;
        count++;
        time[i]=count;
    }
    for(int i=fs;i<ps;i++){
        int flag=0;
        for(int j=0;j<fs;j++){
            if(page[i]==f[j]){
                count++;
                time[j]=count;
                flag=1;
            }
        }
        if(flag==0){
            int pos=loc(time,fs);
            count++;
            time[pos]=count;
            page_fault++;
            f[pos]=page[i];
        }
    }
    printf("Total page fault = %d",page_fault);
    return 0;
}