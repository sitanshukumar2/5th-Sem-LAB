//
#include <stdio.h>
int main()
{
    int a, b, x;
    char o;
    printf("Enter number-1: ");
    scanf("%d", &a);
    printf("Enter number-2: ");
    scanf("%d", &b);
    printf("Enter the Operation: ");
    scanf("\n%c", &o);
    switch (o)
    {
    case '+':
        x = a + b;
        printf("a+b=%d", x);
        break;
    case '-':
        printf("a-b=%d", a - b);
        break;
    case '/':
        printf("a/b=%d", a / b);
        break;
    case '*':
        printf("a*b=%d", a * b);
        break;
    default:
        printf("Invalid Operration!");
    }
    return 0;
}
