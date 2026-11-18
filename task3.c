#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    float price;
};

int main()
{
    struct Book books[3];
    int maxIndex = 0;
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Enter ID, Title, Price of book %d: ", i + 1);
        scanf("%d %s %f", &books[i].id, books[i].title, &books[i].price);
        if (books[i].price > books[maxIndex].price)
            maxIndex = i;
    }

    printf("\n Book List \n");
    for (i = 0; i < 3; i++)
        printf("%d %s Rs.%.2f\n", books[i].id, books[i].title, books[i].price);

    printf("\nMost expensive: %s (Rs.%.2f)\n", books[maxIndex].title, books[maxIndex].price);
    return 0;
}