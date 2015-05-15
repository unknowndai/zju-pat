#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    a += b;
    if (a == 0)
    {
        printf("0");
        return 0;
    }
    if (a < 0)
    { 
        printf("-");
        a = -a;
    }
    int factor = 1000000;
    bool notFirst = false;   
    for (int i = 0; i < 3; i++)
    {
        if (a / factor || notFirst)
        {
            if (notFirst)
                printf(",%03d", a / factor);
            else
            {
                notFirst = true;
                printf("%d", a / factor);
            }
        } 
        a %= factor;
        factor /= 1000;

    }
    return 0;
}

