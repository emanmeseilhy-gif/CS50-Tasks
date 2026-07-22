#include <stdio.h>

int main(void)
{
    long long n;
    if (scanf("%lld", &n) != 1)
    {
        return 0;
    }

    // Handle negative numbers if any
    if (n < 0)
    {
        n = -n;
    }

    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    printf("%d\n", sum);

    return 0;
}
