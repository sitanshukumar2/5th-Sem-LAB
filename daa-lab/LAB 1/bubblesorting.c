//WAP to implement Bubble Sort. Take 3 different set of input. For each of the case count the number of comparission to reach final array.
#include <stdio.h>
void bubbleSort(int a[], int n)
{
    int c = 0;
    for (int j = 0; j < n - 1; ++j)
    {
        for (int i = 0; i < n - j - 1; ++i)
        {
            if (a[i] > a[i + 1])
            {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
            c++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", a[i]);
    }
    printf("\n<<<<No. of comparisons>>>>: %d\n", c);
}

int main()
{
    int case1[] = {2, 7, 7, 9, 16, 10, 1};
    int case2[] = {5, 6, 7, 8, 9, 10};
    int case3[] = {10, 9, 8, 7, 6, 5};

    int n1 = sizeof(case1) / sizeof(case1[0]);
    int n2 = sizeof(case2) / sizeof(case2[0]);
    int n3 = sizeof(case3) / sizeof(case3[0]);

    printf("Sorted array in asc:\n");
    bubbleSort(case1, n1);
    printf("---------------------------------\n");
    printf("Sorted array in asc:\n");
    bubbleSort(case2, n2);
    printf("---------------------------------\n");
    printf("Sorted array in asc:\n");
    bubbleSort(case3, n3);
    printf("----------------------------------\n");
    return 0;
}
