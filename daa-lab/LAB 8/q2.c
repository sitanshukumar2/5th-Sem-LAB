/*Write a program to implement the activity-selection problem stated as follows:
You are given n activities with their start and finish times. Select the maximum number
of activities that can be performed by a single person, assuming that a person can only
work on a single activity at a time. Example: Consider the following 6 activities ( 0, 1, 2,
3, 4, 5). start[] = {1, 3, 0, 5, 8, 5}; finish[] = {2, 4, 6, 7, 9, 9}; The maximum set of
activities that can be executed by a single person is {0, 1, 3, 4}.*/

#include <stdio.h>
int main()
{
   int start[] = {1,3,0,5,8,5};
   int finish[] = {2,4,6,7,9,9};
   int activities = sizeof(start)/sizeof(start[0]);
   int i, j;
   printf ("Selected activities : \n");
   i = 0;
   printf("%d ", i);
   for (j = 1; j < activities; j++)
    {
      if (start[j] >= finish[i])
        {
         printf ("%d ", j);
         i = j;
        }
    }
   return 0;
}