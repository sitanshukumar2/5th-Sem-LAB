// Write a program to rearrange the elements of an array of n integers such that all even numbers are followed by all
// odd numbers. How many different ways you can solve this program. Write your approaches and strategy for solving
// this problem.

#include<stdio.h>
#define N 10

int main()
{
    int a[N], i, j = N, temp;
    printf("Enter %d integer numbers\n", N);
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for(i = 0; i <= j; i++)
    {
        if(a[i] % 2 == 0)
        {
            while(j > i)
            {
                j--;
                if(a[j] % 2 != 0)
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    break;
                }
            }
        }
    }
    printf("\nAfter re-arranging odd and even elements ...\n");
    for(i = 0; i < N; i++)
        printf(" %d", a[i]);
    return 0;
}
