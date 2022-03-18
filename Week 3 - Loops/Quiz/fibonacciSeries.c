#include <stdio.h>

int main(void)
{
  int index, firstHolder = 0, secondHolder = 1;
  printf("Enter a index:\n");
  scanf("%d", &index);
  /* Prints the basic start of the series */
  printf("%d %d ", firstHolder, secondHolder);
  /*
  ** Each loop adds the last two terms to the secondHolder
  ** and stores the old value of the second holder in the firstHolder
  ** try to think of it using pen and paper if you don't get it
  */
  for (int i = 0; i < index - 2; i++)
  {
    /* secondHolder = secondHolder + firstHolder */
    secondHolder += firstHolder;
    /* firstHolder = (new) secondHolder - firstHolder = (old) secondHolder */
    firstHolder = secondHolder - firstHolder;
    printf("%d ", secondHolder);
  }
  printf("\n");
  return 0;
}