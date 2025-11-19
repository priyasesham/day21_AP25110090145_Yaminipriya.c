#include <stdio.h>

#define MAX 50

void inputData(int id[], int speed[], int lane[], int n);
int countSpeedViolations(int speed[], int n);
int countLaneViolations(int lane[], int n);
int busiestLane(int lane[], int n);
int leastBusyLane(int lane[], int n);
void displayReport(int id[], int speed[], int lane[], int n);

int main() 
{
    int n;
    int id[MAX], speedArr[MAX], laneArr[MAX];

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    inputData(id, speedArr, laneArr, n);
    displayReport(id, speedArr, laneArr, n);

    printf("\nTotal Speed Violations: %d", countSpeedViolations(speedArr, n));
    printf("\nTotal Lane Violations: %d", countLaneViolations(laneArr, n));
    printf("\nBusiest Lane: %d", busiestLane(laneArr, n));
    printf("\nLeast Busy Lane: %d\n", leastBusyLane(laneArr, n));
    return 0;
}

void inputData(int id[], int speed[], int lane[], int n) 
{
    for(int i = 0; i < n; i++) 
    {
        printf("\nVehicle %d ID: ", i + 1);
        scanf("%d", &id[i]);
        printf("Speed: ");
        scanf("%d", &speed[i]);
        printf("Lane: ");
        scanf("%d", &lane[i]);
    }
}

int countSpeedViolations(int speed[], int n) 
{
    int count = 0;

    for(int i = 0; i < n; i++)
        if(speed[i] > 80)
            count++;
    return count;
}

int countLaneViolations(int lane[], int n) 
{
    int count = 0;

    for(int i = 0; i < n; i++)
        if(lane[i] < 1 || lane[i] > 4)
            count++;
    return count;
}

int busiestLane(int lane[], int n) 
{
    int f[5] = {0};

    for(int i = 0; i < n; i++)
        if(lane[i] >= 1 && lane[i] <= 4)
            f[lane[i]]++;

    int max = 1;

    for(int i = 2; i <= 4; i++)
        if(f[i] > f[max])
            max = i;
    return max;
}

int leastBusyLane(int lane[], int n) 
{
    int f[5] = {0};

    for(int i = 0; i < n; i++)
        if(lane[i] >= 1 && lane[i] <= 4)
            f[lane[i]]++;

    int min = 1;

    for(int i = 2; i <= 4; i++)
        if(f[i] < f[min])
            min = i;
    return min;
}

void displayReport(int id[], int speed[], int lane[], int n) 
{
    printf("\n\nVehID\tSpeed\tLane\tSpeedViolation");

    for(int i = 0; i < n; i++) 
    {
        printf("\n%d\t%d\t%d\t", id[i], speed[i], lane[i]);
        if(speed[i] > 80)
            printf("YES");
        else
            printf("NO");
    }
   printf("\n");
}
