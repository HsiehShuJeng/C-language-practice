#include <stdio.h>
#include <stdlib.h>
void hanoi(int, char, char, char);
int time = 0;
int main(void)
{
    int height;

    printf("Height of the tower of Hanoi:");
    scanf("%d", &height);
    hanoi(height, 'A', 'B', 'C');

    printf("Total moves from the %d-level high tower: %d times\n", height, time);

    system("pause");
}

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("%d: Move the %d disk from %c to %c\n", ++time, n, A, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        printf("%d: Move the %d disk from %c to %c\n", ++time, n, A, C);
        hanoi(n - 1, B, A, C);
    }
}
