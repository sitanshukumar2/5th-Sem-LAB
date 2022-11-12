/*Write a program that uses a divide-and-conquer algorithm/user defined function for the
exponentiation problem of computing a^n where a > 0 and n is a positive integer.*/
#include <stdio.h>

int power(int a, int n)
    {
    int sol = 1;
    for (n; n > 0; n--)
        {
            sol = sol * n;
        }
    return sol;
    }

int main()
{
    int a,n;
    printf("Enter number : ");
    scanf("%d",&a);
    printf("Enter power of the number : ");
    scanf("%d",&n);
    printf("Value of %d ^ %d : %d",a,n,power(a,n));
    return 0;

} 