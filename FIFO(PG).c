#include<stdio.h>

int front = -1;
int rear = -1;

void push(int a[], int n, int s, int flag)
{
    if(front == -1 && rear ==-1)
    {
        rear = front = 0;
        a[rear] = s;
        printf("FAULT\n");
    }
    else{

        for(int i=0;i<=rear;i++){
            if(a[i] == s)
            {
                flag = 1;
                printf("HIT\n");
                break;
            }
        }
        if(flag == 0)
        {
            printf("FAULT\n");
            if(rear == n-1)
            {
                a[front] = s;
                //front = (front+1) % n;
                (front +=1 )%n;
            }
            else{
                rear = (rear + 1) % n;
                a[rear] = s;
            }
        }

        printf("Arr\n");
        for(int i=0;i<=rear;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}

void main(){
    int n;
    printf("Enter the size of the frame \n");
    scanf("%d",&n);
    int a[n];

    int pg;
    printf("Enter the size of the page references\n");
    scanf("%d", &pg);

    int pr[pg];

    printf("Enter the page references\n");
    for(int i=0; i < pg;i++)
    {
        scanf("%d",&pr[i]);
        push(a, n, pr[i], 0);
    }
}
