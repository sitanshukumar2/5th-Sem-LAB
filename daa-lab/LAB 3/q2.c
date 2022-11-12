// Rewrite the above program (Insertion Sort) with the following details.
//i. Compare the best case, worst case and average case time complexity with the same
//data except time complexity will count the CPU clock time.
//ii. Plot a graph showing the comparison (n, the input data Vs. CPU times for
//best, worst & average case)
//iii. Compare manually previous program graph vs this program graph and draw your
//inference. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// insertion sort
void insertionSort(int* arr, int n)
{
    int i, key, j; 
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
} 
// reverse array
void reverseArray(int* arr, int n)
{
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printTable() {
    int *arr;
    double time;
    time_t start, end;
    printf("\nSl.No.\tN\tTime Complexity\n");
    printf("\t\tRandom\t\tSorted\t\tReverse\n");
    for(int n = 5000, i = 0; i < 10; i++, n+=5000) {
        arr = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            arr[j] = rand() % 100;
        }
        start = clock();
        insertionSort(arr, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%d\t%2f\t", i+1, n, time);
        
        start = clock();
        insertionSort(arr, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%2f\t", time);

        reverseArray(arr, n);
        start = clock();
        insertionSort(arr, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%2f\n", time);
        free(arr);
    }
}

int main()
{
    int choice;
    int n;
    int* arr;
    time_t start, end;

    printf("**MENU**\n");
    printf("0. Quit\n");
    printf("1. n Random numbers => Array\n");
    printf("2. Display the Array\n");
    printf("3. Sort the array in Ascending Order by using Insertion Sort Algorithm\n");
    printf("4. Sort the array in Descending Order by using Insertion Sort Algorithm\n");
    printf("5. Time Taken to sort ascending of random data\n");
    printf("6. Time Taken to sort ascending of data already sorted in ascending order\n");
    printf("7. Time Taken to sort ascending of data already sorted in descending order\n");
    printf("8. Time Taken to sort ascending of data for all Cases\n");
    printf("   (Data in Ascending, Data in Descending and Random Data)\n");
    printf("   in Tabular form for values n = 5000 to 50000, step = 5000\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            printf("Quitting...\n");
            return 0;
        case 1:
            printf("Enter number of elements of array: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            // generate random number of array
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 100;
            }
            break;
        case 2:
            printf("Array: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("Array Sorted to Ascending Order\n");
            // calculate runtime of insertion sort
            insertionSort(arr, n);
            break;
        case 4:
            printf("Array Sorted to Descending Order\n");
            insertionSort(arr, n);
            reverseArray(arr, n);
            break;
        case 5: 
            printf("Enter number of elements of array: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            // generate random number of array
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 100;
            }
            start = clock();
            insertionSort(arr, n);
            end = clock();
            printf("Time taken to sort ascending of random data: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        case 6: 
            insertionSort(arr, n);
            start = clock();
            insertionSort(arr, n);
            end = clock();
            printf("Time taken to sort ascending of random data: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        case 7:
            insertionSort(arr, n);
            reverseArray(arr, n);
            start = clock();
            insertionSort(arr, n);
            end = clock();
            printf("Time taken to sort ascending of random data: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        case 8:
            printTable();
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}