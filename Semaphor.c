#include<stdio.h>
int mutex=1;
int full=0;
int empty=5;
int x=0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("producer produce item %d \n",x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item %d \n",x);
    x--;
    ++mutex;
}
int main()
{
    int n,i;
    printf("Choose \n 1.Producer \n 2.Consumer \n 3.Exit \n");
    for(i=1;i>0;i++)
    {
        printf("Enter the choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : if(mutex==1 && empty!=0)
                       {
                         producer();
                       }
                       else
                       {
                         printf("Buffer is full \n");
                       }
                    break;
            
            case 2 : if (mutex==1 && full!=0)
                      {
                        consumer();
                      }
                      else
                      {
                        printf("buffer empty\n");
                      }
                    break;

            case 3 : break;
        }
    }
}