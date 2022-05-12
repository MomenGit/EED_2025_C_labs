#include <stdio.h>

void solve()
{
    int a = 3;
    /*        3   4   5   5   6   7 */
    int res = a++ + ++a + a++ + ++a;
    /* Therefore a = 3 + 5 + 5 + 7 = 20 */
    printf("%d", res);
}
int main()
{
    solve();
    return 0;
}