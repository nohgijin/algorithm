#include <stdio.h>

int main()
{
    int A, B;
    int result = 0;
    scanf("%d %d", &A, &B);
    for (int i = A; i < B; i++)
    {
        printf("%d + ", i);
        result += i;
    }
    result += B;
    printf("%d = %d", B, result);
}