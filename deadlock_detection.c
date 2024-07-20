// Banker's Algorithm
#include <stdio.h>
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int n, m, i, j, k;
    n = 4; // Number of processes
    m = 3; // Number of resources
    int alloc[4][3] = { { 1, 0, 2 }, // P0    // Allocation Matrix
                        { 2, 1, 1 }, // P1
                        { 1, 0, 3 }, // P2
                        { 1, 2, 2 }, // P3
                        }; // P4

    int req[4][3] = { { 0, 0, 1 }, // P0    // MAX Matrix
                      { 1, 0, 2 }, // P1
                      { 0, 0, 0 }, // P2
                       // P3
                      { 3, 3, 0 } }; // P4

    int avail[3] = { 0, 0, 0}; // Available Resources

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    int y = 0;

    // how many we want to check the safe
    for (k = 0; k < 4; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {


                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (req[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

      int flag = 1;

      for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;

         printf("The following system is not safe\n");
         for(int l=0;l<n;l++){
            if(f[l] == 0)
            {
                printf("P%d is causing deadlock\n",l);
            }
         }

        break;
      }
    }

      if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }


    return (0);
}
