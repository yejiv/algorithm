#include <stdio.h>

int main()
{
    int loop;
    int num;
    long memo[100] = { 1, 0, 1};

    scanf("%d", &loop);

    for(int i = 0; i < loop; ++i)
    {
        scanf("%d", &num);

        for(int j = 3; j < num + 2; ++j)
            memo[j] = memo[j - 1] + memo[j - 2];

        printf("%ld %ld\n", memo[num], memo[num + 1]);
    }

    return 0;
}