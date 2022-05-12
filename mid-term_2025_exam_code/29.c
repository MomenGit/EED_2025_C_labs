#include <stdio.h>

void solve()
{
    int x = 2;
    printf("%d", (x << 1) + (x >> 1));
}
int main()
{
    solve();
    return 0;
}