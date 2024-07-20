#include<stdio.h>
// # define n 4
struct gt
{
    char p[2];
    int a;
    int bt;
    int c;
    int wt;
    int tat;
    int start_time;
    int end_time;
    int rt;
};

void main()
{
    int n;
    printf("En n:");
    scanf("%d", &n);

    struct gt ob[n];
    printf("Enter the process names\n");
    for(int i=0;i<n;i++)
        scanf("%s",&ob[i].p);



    for(int i=0;i<n;i++)
    {
        printf("Enter the Arrival time and Burst Time of the process %s:",ob[i].p);
        scanf("%d %d",&ob[i].a, &ob[i].bt);
        printf("\n");
    }

    // Sorted arrival time
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(ob[j].a > ob[j+1].a)
            {
                struct gt temp = ob[j];
                ob[j] = ob[j+1];
                ob[j+1] = temp;
            }
        }
    }

    // Gantt Chart with start time and end time
    int s = 0;
    for(int i=0;i<n;i++)
    {
        ob[i].start_time = (ob[i].a > s) ? ob[i].a : s;
        ob[i].end_time = (ob[i].start_time) + ob[i].bt;
        s = ob[i].end_time;
    }


    // Calculation
    float s_tat = 0;
    float s_wt = 0;
    for(int i=0;i<n;i++)
    {
        ob[i].tat = ob[i].end_time - ob[i].a;
    }

    for(int i=0;i<n;i++)
    {
        ob[i].wt = ob[i].tat - ob[i].bt;
        ob[i].rt = ob[i].start_time - ob[i].a;
    }

    for(int i=0;i<n;i++)
    {
        s_tat += ob[i].tat;
        s_wt += ob[i].wt;
    }

    float avg_tat = s_tat / (float)n;
    float avg_wt = s_wt / (float)n;

printf("PROCESS \t BURST TIME \t ARRIVAL TIME \t TURN AROUND TIME \t WAITING TIME \t Response Time\n");
    for(int i = 0;i<n;i++)
    {

        printf("%s\t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d\n", ob[i].p, ob[i].bt, ob[i].a, ob[i].tat, ob[i].wt, ob[i].rt);
    }

printf("Average Waiting Time: %f\n",avg_wt);
printf("Average Turn Around Time: %f\n",avg_tat);

float s_rt = 0;
for(int i=0;i<n;i++)
{
    s_rt = s_rt +(ob[i].start_time - ob[i].a);
}
printf("Average Response Time = %f", (s_rt/n));

}
