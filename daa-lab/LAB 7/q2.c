/*Similar to above program, write a menu driven program to sort an array of n integers in descending order by heap sort algorithm, use min heap.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

void heapify(int arr[], int N, int i)
{
	int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < N && arr[l] < arr[smallest])
        smallest = l;

    if (r < N && arr[r] < arr[smallest])
        smallest = r;
 
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, N, smallest);
    }
}

void heapSort(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
    int i, num;
    printf("Enter the size of array:");
    scanf("%d", &num);
    int arr[num];
    for (i = 0; i < num; i++)
        arr[i] = rand() % 10000;
	int N = sizeof(arr) / sizeof(arr[0]);

    clock_t t1;
    t1 = clock();

	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
    t1 = clock() - t1;
    double time_taken = (double)t1 / (double)CLOCKS_PER_SEC;
    printf("\nTime: %f\n", time_taken);
}