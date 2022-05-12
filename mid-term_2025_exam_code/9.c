#include <stdio.h>

void test(int *pr)
{
    int x = 100;
    pr = &x;
}
int main()
{
    int num = 200;
    int *pr = &num;
    test(pr);
    printf("%d", *pr);
    return 0;
}