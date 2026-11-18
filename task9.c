#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee emp;
    int i, searchId, found = 0;
    float total = 0;
    char choice;

    fp = fopen("employees.dat", "wb");
    if (fp == NULL)
    {
        printf("Cannot create file\n");
        return 1;
    }

    for (i = 0; i < 5; i++)
    {
        printf("Enter ID, Name, Monthly Salary of employee %d: ", i + 1);
        scanf("%d %s %f", &emp.id, emp.name, &emp.salary);
        fwrite(&emp, sizeof(struct Employee), 1, fp);
    }
    fclose(fp);

    fp = fopen("employees.dat", "rb");
    if (fp == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    printf("\n--- All Employees ---\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1)
    {
        printf("%d %s %.2f\n", emp.id, emp.name, emp.salary);
        total = total + emp.salary;
    }
    printf("\nTotal monthly salary: %.2f\n", total);

    printf("\nEnter ID to search: ");
    scanf("%d", &searchId);
    rewind(fp);
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1)
    {
        if (emp.id == searchId)
        {
            printf("Found: %d %s %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
        }
    }
    if (found == 0)
        printf("Employee not found\n");
    fclose(fp);

    printf("\nDelete the file? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        if (remove("employees.dat") == 0)
            printf("File deleted\n");
        else
            printf("Could not delete file\n");
    }
    return 0;
}