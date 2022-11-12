#include <stdio.h>
#include <string.h>
int main()
{
    printf("Enter a Sentence - ");
    char str[100];
    scanf("%[^\n]s", str);
    printf("%s", str);
    int p = 0;
    int q = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            continue;
        else
            p++;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            q++;
    }
    printf("\nNumber of letters = %d", p / q);
}
