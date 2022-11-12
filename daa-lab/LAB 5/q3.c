/*Let A be an array of n integers a0,a1,... ,an-1 (negative integers are allowed), denoted, by A[i... j], the sub-array ai, ai+1,... ,aj for i≤j. Also let Si-j denote the sum ai + ai+1 +· · · + aj. Write a program by using an udf that must run in O(n2) time to find out the maximum value of Si-j for all the pair i, j with 0 ≤ i ≤ j ≤ n-1. empty sub-array will have sum Si-j = 0. Indeed, if all the elements of A are negative, then one returns 0 as the maximum sub-array sum.*/

#include <stdio.h>
int maximum_value(int a[], int l)
{
    int i, x, j, max;
    max = 0;
    for(i=0;i<(l-1);i++)
    {
        x = a[i];
        for(j=(i+1);j<l;j++)
        {
            x = x + a[j];
            if(x>max)
            {
                max = x;
            }
        }
    }
    if(max<0)
    {
        max = 0;
    }
    return (max);
}
int main()
{
    int len, i;
    printf("Enter the legth of the list:\n");
    scanf("%d", &len);
    int a[len];
    printf("Enter the numbers in the list:\n");
    for(i=0;i<len;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Maximum value that you can get out of the entered list of numbers is %d", maximum_value(a, len));
}