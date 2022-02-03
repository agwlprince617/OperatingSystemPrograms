#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty=3,x=0;
 
int main()
{
    int n;
    void producer();
    void consumer();
    int dec(int);
    int inc(int);
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(n!=3)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:    if((mutex==1)&&(empty!=0))
                        producer();
                    else
                        printf("Buffer is full!!");
                    break;
            case 2:    if((mutex==1)&&(full!=0))
                        consumer();
                    else
                        printf("Buffer is empty!!");
                    break;
            case 3:
                    exit(0);
                    break;
        }
    }
   
    return 0;
}
 
int dec(int s)
{
    return (--s);
}
 
int inc(int s)
{
    return(++s);
}

void producer()
{
    mutex=dec(mutex);
    full=inc(full);
    empty=dec(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex=inc(mutex);
}
 
void consumer()
{
    mutex=dec(mutex);
    full=dec(full);
    empty=inc(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=inc(mutex);
}