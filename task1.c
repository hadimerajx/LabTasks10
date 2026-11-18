#include <stdio.h>

int totalCalories(int n)
{
    if (n==0)
        return 0;
    return (n * 5) + totalCalories(n - 1);
}
int main()
{
    int n;
    printf("Enter Number of Steps: ");
    scanf("%d", &n);
    printf("Total Calories Burned: %d \n", totalCalories(n));
    return 0;
}