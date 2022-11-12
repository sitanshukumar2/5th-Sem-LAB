/*. Write a program by using an user defined function for computing  √n for any positive integer n. Besides assignment and comparison, your algorithm may only use the four basic arithmetical operations*/
#include <stdio.h>
float sqroot(float x)
{
	if (x == 0 || x == 1)
	return x;
	float i = 1, result = 1;
	while (result <= x)
	{
	i++;
	result = i * i;
	}
    return i - 1;
}

int main()
{
    float n;
    printf("Enter number : ");
    scanf("%f",&n);
    printf("Sq. Root : %f",sqroot(n));
return 0;
}

