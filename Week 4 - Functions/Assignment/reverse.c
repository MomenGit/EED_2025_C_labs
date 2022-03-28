#include <stdio.h>
#include <math.h>

int reverseNumber(int number);
int main()
{
    int input;
    printf("Enter a number:\n");
    scanf("%d", &input);

    printf("The reversed number is: %d\n", reverseNumber(input));
    return 0;
}
// Return reverse of a number
int reverseNumber(int number)
{
    int reversed = 0, numberOfDigits = (int)log10f((number < 0) ? number * -1 : number * 1); // number of digits is actually number of digits - 1

    for (int i = 0; i <= numberOfDigits; i++)
        reversed += (number / (int)powf(10, i) % 10) * (int)powf(10, numberOfDigits - i);

    /* check if the last small digit was a zero then multiply the reversed number by 10 to keep the zero in its place */
    if ((number / (int)powf(10, 0) % 10) == 0)
        reversed *= 10;

    return reversed;
}