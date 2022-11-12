/*You are given n activities with their start and finish times, input through keyboard.
Write a program to select all possible maximum number of activities that can be
performed by a single person including one activity of his/her choice, assuming that a
person can only work on a single activity at a time.*/

#include <stdio.h>
int main()
{
    int n;
    printf("Enter no. of activities : ");
    scanf("%d",&n);
    char name[100];
   // int start[100],finish[100];
    int activity[100][100];
    for(int a=0;a<n;a++)
        {
            printf("Enter name of activity : ");
            scanf("%c",&name[a]);
            for(int b=0;b<n;b++)
            {
                printf("Enter start and finish time : ");
                scanf("%d %d",&activity[n][n]);
            }
        }
      for(int a=0;a<n;a++)
        {
            printf("Activity : %d",name[a]);
            for(int b=0;b<n;b++)
            {
                printf("Enter start and finish time : %d %d",activity[n][n]);
            }
        }
   int i, j;
   printf ("Selected activities : \n");
   i = 0;
   printf("%d ", i);
   for (j = 1; j<n; j++)
    {
      if (start[j] >= finish[i])
        {
         printf ("%d ", j);
         i = j;
        }
    }
   return 0;
}
