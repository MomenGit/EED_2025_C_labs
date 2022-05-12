#include <stdio.h>

void solve()
{
    char ch[10] = "abcdefghij";
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += (ch[i] - 'a');
    }
    printf("%d", ans);
}
int main()
{
    solve();
    return 0;
}