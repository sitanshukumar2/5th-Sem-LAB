#include <stdio.h>
struct student
{
    char name[20];
    int id, phone;
};
int main()
{
    struct student s[10];
    for (int i = 0; i < 2; i++)
    {
        printf("Enter Details of Student %d:\n", i + 1);
        printf("Enter Name: ");
        scanf("%[^\n]s", s[i].name);
        printf("Enter Id: ");
        scanf("%d", &s[i].id);
        printf("Enter Phone: ");
        scanf("%d", &s[i].phone);
        scanf("%c");
    }
    for (int i = 0; i < 2; i++)
    {
        printf("Details of Student %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("ID: %d\n", s[i].id);
        printf("Phone: %d\n", s[i].phone);
    }
}
