#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int booked_ticket = 0;
int max_ticket = 10;


void book_ticket()
{
    --mutex;
    ++booked_ticket;
    --max_ticket;
    printf("\n%d TICKET BOOKED SUCCESSFULLY\n",booked_ticket);
    ++mutex;
}
  

void cancel_ticket()
{
    --mutex;
    --booked_ticket;
    ++max_ticket;
    printf("\nTICKET CANCELED\n");
    ++mutex;
}
int main()
{
    int n, i;
    printf("\n1. SHOW STATUS"
           "\n2. BOOK TICKET"
           "\n3. CANCEL TICKET"
           "\n4. EXIT\n");
  
  
    while(1){
  
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n) {
        case 1:
                printf("\nNumber of Avilable tickets : %d\n",max_ticket);
                break;
        case 2:

            if ((mutex == 1)&& (max_ticket!= 0)) {
                book_ticket();
            }

            else {
                printf("\nBOOKING FULL!!.\n");
            }
            break;
  
        case 3:

            if ((mutex == 1)&& (booked_ticket!= 0)) {
                cancel_ticket();
            }

            else {
                printf("\nNO TICKET TO CANCEL \n");
            }
            break;
        case 4:
            exit(0);
            break;
        }
    }
}