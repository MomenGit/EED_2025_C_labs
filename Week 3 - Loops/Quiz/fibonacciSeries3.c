#include <stdio.h>

int main(void)
{
  int index, firstHolder = 0, secondHolder = 1, thirdHolder = 1;
  printf("Enter a index:\n");
  scanf("%d", &index);
  /* Prints the basic start of the series */
  printf("%d %d %d ", firstHolder, secondHolder, thirdHolder);
  /*
  ** Each loop adds the last three terms to the thirdHolder
  ** , stores the old value of the thirdholder in the secondHolder
  ** and stores the old value of the secondholder in the firstHolder
  ** try to think of it using pen and paper if you don't get it
  */
  for (int i = 0; i < index - 3; i++)
  {
    /* thirdHolder = thirdHolder + secondHolder + firstHolder */
    thirdHolder += secondHolder + firstHolder;
    /* secondHolder = thirdHolder(new) - secondHolder - firstHolder = (old)thirdHolder */
    secondHolder = thirdHolder - secondHolder - firstHolder;
    /* firstHolder = thirdHolder(new) - secondHolder(new) - firstHolder = (old)secondHolder */
    firstHolder = thirdHolder - secondHolder - firstHolder;
    printf("%d ", thirdHolder);
  }
  printf("\n");
  return 0;
}