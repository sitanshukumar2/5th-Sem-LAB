// Write a program to test whether a number n is prime or not by using different algorithms for 10 inputs and note
// down time complexity by step count methodfor each algorithm. Make a comparison of time complexities found for different algorithms
// inputs and plot a graph and decide which  algorithm is faster.
#include <stdio.h>
#include <math.h>
void Prime1(int n)
{
    int c = 0, count = 0;
    if (n == 0 || n == 1)
    {
        count++;
        printf("%d is a not a Prime number.\n", n);
        printf("No. of Steps: %d\n", count);
        return;
    }
    for (int i = 2; i <= n / 2; ++i)
    {
        count++;
        if (n % i == 0)
        {
            c = 1;
            break;
        }
    }
    if (c == 0)
    {
        printf("%d is a Prime number.\n", n);
        printf("No. of Steps: %d\n", count);
    }
    else
    {
        printf("%d is a not a Prime number.\n", n);
        printf("No. of Steps: %d\n", count);
    }
}
int q = 0;
int PrimeRec(int i, int n)
{
    q++;
    if (n == i)
    {
        return 0;
    }
    else if (n % i == 0)
    {
        return 1;
    }
    else
    {
        return PrimeRec(i + 1, n);
    }
}
void Prime2(int n)
{
    int a = PrimeRec(2, n);
    if (a == 1)
    {
        printf("%d is a not a Prime number.\n", n);
        printf("No. of Steps: %d\n", q);
    }
    else
    {
        printf("%d is a Prime number.\n", n);
        printf("No. of Steps: %d\n", q);
    }
}
void Prime3(int n)
{
    int count = 0;
    if (n <= 1)
    {
        count++;
        printf("%d is a not a Prime number.\n", n);
        printf("No. of Steps: %d\n", count);
        return;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        count++;
        if (n % i == 0)
        {
            printf("%d is a not a Prime number.\n", n);
            printf("No. of Steps: %d", count);
            return;
        }
    }
    printf("%d is a Prime number.\n", n);
    printf("No. of Steps: %d", count);
}
int main()
{
    Prime1(11);
    Prime2(11);
    Prime3(11);
}
