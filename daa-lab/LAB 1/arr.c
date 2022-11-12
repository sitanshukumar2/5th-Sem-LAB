//WAP to find the Frequency of repitition of numbers in an array
#include <stdio.h>

int main()
{
    int a[] = {1, 3, 7, 3, 9, 3, 2, 3, 1};
    int length = sizeof(a)/sizeof(a[0]);

    int fr[length];
    int visited = -1;

    for(int i = 0; i < length; i++)
    {
        int count = 1;
        for(int j = i+1; j < length; j++)
        {
            if(a[i] == a[j])
            {
                count++;
                fr[j] = visited;
            }
        }
        if(fr[i] != visited)
            fr[i] = count;
    }

    printf(" Element  Frequency\n");
    for(int i = 0; i < length; i++)
    {
        if(fr[i] != visited)
        {
            printf("    %d\t", a[i]);

            printf("    %d\n", fr[i]);
        }
    }

    return 0;
}
