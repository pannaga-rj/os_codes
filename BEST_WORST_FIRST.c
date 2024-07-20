#include<stdio.h>

void main()
{

    int a[5], v[4];
    int m[] = {100, 500, 200, 300, 600};
    int p[] = {212, 417, 112, 426};

    for(int j=0;j<5;j++)
    {
        a[j] = -1;
    }


    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<5;j++)
        {
            if(p[i] < m[j]  && a[j] == -1)
            {
                a[j] = p[i];
                break;
            }
        }
    }

    printf("First fit\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);

    }

    for(int j=0;j<5;j++)
    {
        a[j] = -1;
    }
    int index;
    for(int i=0;i<4;i++)
    {
        index = -1;
        for(int j=0;j<5;j++)
        {
            if(m[j] >= p[i] && a[j] == -1 &&(index == -1 || m[j] < m[index])){
                index = j;
            }
        }

        if(index != -1)
            a[index] = p[i];
    }


    printf("\nBest fit\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }


    for(int j=0;j<5;j++)
    {
        a[j] = -1;
    }
    for(int i=0;i<4;i++)
    {
        index = -1;
        for(int j=0;j<5;j++)
        {
            if(m[j] >= p[i] && a[j] == -1 &&(index == -1 || m[j] > m[index])){
                index = j;
            }
        }

        if(index != -1)
            a[index] = p[i];
    }


    printf("\nWorst fit\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }

}
