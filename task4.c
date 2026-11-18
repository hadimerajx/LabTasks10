#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    struct Employee emp[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Enter ID, Name, Salary: ");
        scanf("%d %s %f", &emp[i].id, emp[i].name, &emp[i].salary);
        if (emp[i].salary < 50000)
            emp[i].salary = emp[i].salary + emp[i].salary * 0.10;
    }

    printf("\n--- Updated Salaries ---\n");
    for (i = 0; i < 3; i++)
        printf("%d %s %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    return 0;
}