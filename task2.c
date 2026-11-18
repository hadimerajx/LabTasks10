#include <stdio.h>

void reverseDigits(long num)
{
    if (num == 0)
        return;
    printf("%ld", num % 10);
    reverseDigits(num/10);
    
}

int main()
{
    long num;
    printf("Enter The Number: ");
    scanf("%ld", &num);
    printf("Reversed Number Is: ");
    reverseDigits(num);
    return 0;
}