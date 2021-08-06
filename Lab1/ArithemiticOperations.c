/* 
 * ArithmeticOperators.c
 * peforms various arithmetic operations
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
  int value1; // first value from user
  int value2; // second value from user
  int result; // result variable

  // read in value1 and value2
  printf("Please enter two integer values: ");
  scanf("%d%d", &value1, &value2);
  
  // obtain and print positive value1
  result = +value1;
  printf("+%d = %d\n", value1, result);
  // obtain and print negative value1
  result = -value1;
  printf("-%d = %d\n", value1, result);
  // obtain and print incremented value1
  result = ++value1;
  // revert side effect of ++
  --value1;
  printf("++%d = %d\n", value1, result);
  // obtain and print decremented value1
  result = --value1;
  // revert side effect of --
  ++value1;  
  printf("--%d = %d\n", value1, result);
  // obtain and print value1 plus value2
  result = value1 + value2;
  printf("%d + %d = %d\n", value1, value2, result);
  // obtain and print value1 minus value2
  result = value1 - value2;
  printf("%d - %d = %d\n", value1, value2, result);
  // obtain and print value1 multiplied by value2
  result = value1 * value2;
  printf("%d * %d = %d\n", value1, value2, result);
  // obtain and print value1 divided by value2
  result = value1 / value2;
  printf("%d / %d = %d\n", value1, value2, result);
  // obtain and print remainder of value1 divided by value2
  result = value1 % value2;
  printf("%d %% %d = %d\n", value1, value2, result);

  return EXIT_SUCCESS;
}
