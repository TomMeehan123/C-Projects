/*
 * SwitchMenu.c
 * present a menu for calucation, use switch
 * to react to user input
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
  int input; // variable for user input
  double num1, num2; // numbers for calculations
  
  do {

    printf("Please choose from the following options:\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Multiplication\n");
    printf("4) Division\n");
    printf("5) Exit\n");
    printf("\nYour Choice: ");
    // read in choice from user
    scanf("%i", &input);

    switch (input) {
    case 1: // addition
      printf("Please enter two numbers: ");
      scanf("%lf%lf",&num1, &num2);
      printf("\n%f + %f = %f\n\n", num1, num2, num1+num2);
      break;
    case 2: // subtraction
      printf("Please enter two numbers: ");
      scanf("%lf%lf",&num1, &num2);
      printf("\n%f - %f = %f\n\n", num1, num2, num1-num2);
      break;
    case 3: // multiplication
      printf("Please enter two numbers: ");
      scanf("%lf%lf",&num1, &num2);
      printf("\n%f * %f = %f\n\n", num1, num2, num1*num2);
      break;
    case 4: // division
      printf("Please enter two numbers: ");
      scanf("%lf%lf",&num1, &num2);
      if (num2 != 0) {
	printf("\n%f / %f = %f\n\n", num1, num2, num1/num2);
      } else {
	printf("\nDivision by zero not allowed\n\n");
      }
      break;
    case 5: // exit
      // nothing needs to be done
      break;
    default:
      printf("You entered an illegal choice, please "
	     "enter only numbers 1 - 5!\n");
    }
  } while (input != 5);

  return EXIT_SUCCESS;
}
