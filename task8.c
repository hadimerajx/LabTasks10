#include <stdio.h>

int main()
{
    FILE *fp;
    char title[50], author[50];
    int id, searchId, choice, found;

    do
    {
        printf("\n1. Add book\n2. Display all books\n3. Search by ID\n4. Delete file\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            fp = fopen("library.txt", "a");
            if (fp == NULL)
                printf("Cannot open file\n");
            else
            {
                printf("Enter ID, Title, Author: ");
                scanf("%d %s %s", &id, title, author);
                fprintf(fp, "%d %s %s\n", id, title, author);
                fclose(fp);
                printf("Book added\n");
            }
        }
        else if (choice == 2)
        {
            fp = fopen("library.txt", "r");
            if (fp == NULL)
                printf("No records found\n");
            else
            {
                printf("\n--- Book Records ---\n");
                while (fscanf(fp, "%d %s %s", &id, title, author) == 3)
                    printf("ID: %d | Title: %s | Author: %s\n", id, title, author);
                fclose(fp);
            }
        }
        else if (choice == 3)
        {
            fp = fopen("library.txt", "r");
            if (fp == NULL)
                printf("No records found\n");
            else
            {
                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);
                found = 0;
                while (fscanf(fp, "%d %s %s", &id, title, author) == 3)
                {
                    if (id == searchId)
                    {
                        printf("Found: ID: %d | Title: %s | Author: %s\n", id, title, author);
                        found = 1;
                    }
                }
                if (found == 0)
                    printf("Book not found\n");
                fclose(fp);
            }
        }
        else if (choice == 4)
        {
            if (remove("library.txt") == 0)
                printf("File deleted\n");
            else
                printf("File does not exist\n");
        }
    } while (choice != 5);

    return 0;
}