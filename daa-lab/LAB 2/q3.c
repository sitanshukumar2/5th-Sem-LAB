//Write a program to swap pair of elements of an array n integers from starting. If n is odd, then last number will
// be remain unchanged.
#include <stdio.h>
int main()
{
    int total;
    int i;
    int temp;
    printf("Enter no. of elements : ");
    scanf("%d", &total);
    int array[total];
    for (i = 0; i < total; i++)
    {
        printf(" Element %d : ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Array : \n");
    for (i = 0; i < total; i++)
    {
        printf("%d ", array[i]);
    }
    for (i = 0; i < total; i += 2)
    {
        if (i + 1 == total)
        {
            break;
        }
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
    printf("\nArray after reversing : \n");
    for (i = 0; i < total; i++)
    {
        printf("%d ", array[i]);
    }
}
