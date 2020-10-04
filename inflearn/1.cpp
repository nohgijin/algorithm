#include <stdio.h>

int main()
{
    int N, M;
    int result = 0;
    scanf("%d %d", &N, &M);
    for (int i = 3; i <= N; i++)
    {
        if (i % M == 0)
            result += i;
    }
    printf("%d", result);
}