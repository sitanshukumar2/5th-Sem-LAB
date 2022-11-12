/*Write a program to sort a list of n elements using the merge sort method and determine
the time required to sort the elements. Repeat the experiment for different values of n
and different nature of data (random data, sorted data, reversely sorted data) in the list.
n is the user input and n integers can be generated randomly.*/ 

#include <stdio.h>
#include <time.h>
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void print(int arr[], int size)
{
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    clock_t t1;
    t1 = clock();
    mergeSort(arr, 0, n);
    print(arr, n);
    t1 = clock() - t1;
    double time_taken = (double)t1 / (double)CLOCKS_PER_SEC;
    printf("\nTime: %f\n", time_taken);
    return 0;
}