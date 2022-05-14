#include <stdio.h>

void fn(int **);
int main()
{
    int *j;
    fn(&j);
    return 0;
}
void fn(int **k)
{
    int a = 10;
    /* In case it had semicolon in the choice */
    *k = &a;
}