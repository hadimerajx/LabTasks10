#include <stdio.h>

float totalBill(float prices[], int n)
{
    if (n == 0)
        return 0;
    return prices[n - 1] + totalBill(prices, n - 1);
}

int main()
{
    float prices[100];
    int n, i;
    float total;

    printf("Enter number of products: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of products\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter price of product %d: ", i + 1);
        scanf("%f", &prices[i]);
    }

    total = totalBill(prices, n);
    printf("Total bill: %.2f\n", total);
    printf("Average price: %.2f\n", total / n);
    return 0;
}