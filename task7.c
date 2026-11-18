#include <stdio.h>

int main()
{
    FILE *fp;
    char name[50], status[20];
    int roll, choice, count, i;

    do
    {
        printf("\n1. Add records\n2. Display records\n3. Delete file\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            fp = fopen("attendance.txt", "a");
            if (fp == NULL)
                printf("Cannot open file\n");
            else
            {
                printf("How many students: ");
                scanf("%d", &count);
                for (i = 0; i < count; i++)
                {
                    printf("Enter name, roll number, status (Present/Absent): ");
                    scanf("%s %d %s", name, &roll, status);
                    fprintf(fp, "%s %d %s\n", name, roll, status);
                }
                fclose(fp);
                printf("Records saved\n");
            }
        }
        else if (choice == 2)
        {
            fp = fopen("attendance.txt", "r");
            if (fp == NULL)
                printf("No records found\n");
            else
            {
                printf("\n--- Attendance Records ---\n");
                while (fscanf(fp, "%s %d %s", name, &roll, status) == 3)
                    printf("%s %d %s\n", name, roll, status);
                fclose(fp);
            }
        }
        else if (choice == 3)
        {
            if (remove("attendance.txt") == 0)
                printf("File deleted\n");
            else
                printf("File does not exist\n");
        }
    } while (choice != 4);

    return 0;
}