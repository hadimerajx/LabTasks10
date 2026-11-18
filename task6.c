#include <stdio.h>

int exitVehicles(int parked, int exits)
{
    if (parked <= 0 || exits <= 0)
        return 0;
    printf("Vehicle exited. Remaining: %d\n", parked - 1);
    return 1 + exitVehicles(parked - 1, exits - 1);
}

int main()
{
    int parked, exits, exited, remaining;

    printf("Enter number of vehicles parked: ");
    scanf("%d", &parked);
    printf("Enter number of vehicles exiting: ");
    scanf("%d", &exits);

    exited = exitVehicles(parked, exits);
    remaining = parked - exited;

    printf("Total vehicles exited: %d\n", exited);
    printf("Vehicles remaining: %d\n", remaining);
    if (remaining == 0)
        printf("Parking area is empty\n");
    else
        printf("Parking area is not empty\n");
    return 0;
}