#include<stdio.h>
int main(){
    int ref[20],fr[10],rs,fs;
    printf("Enter size of Ref string\n");
    scanf("%d",&rs);
    printf("Enter Ref string\n");
    for(int i=0;i<rs;i++){
        scanf("%d",&ref[i]);
    }
    printf("Enter size of frames\n");
    scanf("%d",&fs);
    for(int i=0;i<fs;i++){
        fr[i]=0;
    }
    int page_fault=0;
    for(int i=0;i<fs;i++){
        fr[i]=ref[i];
        page_fault++;
    }
   // printf("%d pf ",page_fault);
    int idx=0;
    for(int i=fs;i<rs;i++){
        int flag=0;
        for(int j=0;j<fs;j++){
            if(ref[i]==fr[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            fr[idx]=ref[i];
            idx=(idx+1)%fs;
            //printf("%d idx ",idx);
            page_fault++;
            //printf("%d pf ",page_fault);
        }
    }
    printf("Total number of pagefault %d",page_fault);
    return 0;
}
















