#include <stdio.h>

int main()
{
    int N;
    int result = 0;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
        {
            result += i;
            printf("%d", i);
        }
        else if (N % i == 0)
        {
            result += i;
            printf("+ %d ", i);
        }
    }
    printf("= %d", result);
    return 0;
}