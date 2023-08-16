#include<stdio.h>
#include<stdlib.h>

int mutex=1;
int full =0;
int empty,x=0;

void producer(){
    --mutex;
    --empty;
    ++x;
    printf("\nProducer proces item %d\n",x);
    ++full;
    ++mutex;
}

void consumer(){
    --mutex;
    --full;
    printf("\nConsumer consumed item %d\n",x);
    --x;
    ++empty;
    ++mutex;
}

int main(){
    int n;
    printf("Enter buffer size:");
    scanf("%d",&empty);

    while(1){
        printf("\nEnter your choice:\n1.Produce\n2.Consume\n3.Exit\n");
        scanf("%d",&n);
        switch (n)
        {
        case (1):
            if((mutex==1) && (empty!=0)){
                producer();
            }else{
                printf("\nBuffer is Full!!!\n");
            }
            break;
        case (2):
            if((mutex == 1 )&& (full!=0)){
                consumer();
            }else{
                printf("\nBuffer Empty!!!\n");
            }
            break;
        case (3):
            exit(0);
        default:
            printf("\nInvalid Choice!!!\n");
            break;
        }
    }
}