/*Write a program to implementation of 0/1 Knapsack algorithm using greedy
method.*/

#include <stdio.h>
int max(int a, int b) 
    {
        if (a>b)
            return a;
        else 
            return b;    
    }
//W= knapsack size
//wt= wt of each element
//val= val of each element
//n= no. of elements
int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
		else
		return max(val[n - 1] + knapSack(W - wt[n - 1],wt, val, n - 1),knapSack(W, wt, val, n - 1));
}
int main()
{
	int val[] = { 450, 300, 750 };
	int wt[] = { 40, 90, 70 };
	int W = 160;
	int n = sizeof(val) / sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}
