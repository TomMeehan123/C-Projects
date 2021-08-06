 */
 * Ex4-2-OrderNumbers.c
 * Solution to exericse 4.2 - Order numbers
 * passed to main()
 */

#include <stdlib.h>
#include <stdio.h>


/*
  pseudo-code to estalbish order of three numbers num1,num2,num3
  after code first should be smallest, second middle, third largest value]

  if num1 <= num2 AND num1 <= num 3
    //num 1 is smallest
    first = num1
    if num2 <= num3
       // num2 is middle, num3 is largest
       second = num2
       third = num3
    otherwise 
       // num3 is middle, num2 is largest
       second = num3
       third = num2
  otherwise if num2 <= num1 AND num2 <= num 3
    //num 2 is smallest
    first = num2
    if num1 <= num3
       // num1 is middle, num3 is largest
       second = num1
       third = num3
    otherwise 
       // num3 is middle, num2 is largest
       second = num3
       third = num1
  otherwise 
    //num 3 is smallest
    first = num3
    if num2 <= num1
       // num2 is middle, num1 is largest
       second = num2
       third = num1
    otherwise 
       // num1 is middle, num2 is largest
       second = num1
       third = num2
 */

int main(int argc, const char *argv[]) 
{
  // test for correct number of arguments
  if (argc < 4) {
    printf("incorrect number of arguments.\n"
	   "Please call with %s num1 num2 num3\n", argv[0]);
  } else {
    double num1, num2, num3;     // variables for initial numbers
    double first, second, third; // variables for three numbers
                                 // in ascending order
    // convert arguments (string) to double
    num1 = atof(argv[1]);
    num2 = atof(argv[2]);
    num3 = atof(argv[3]);

    // order numbers
    // if num1 <= num2 AND num1 <= num 3
    if ( (num1<=num2) && (num1<=num3)) {
      // num1 is smallest
      first = num1;
      // order num2 and num3
      if (num2 <= num3) {
	// num2 is middle, num3 is largest
	second = num2;
	third = num3;
      } else {
	// num3 is middle, num2 is largest
	second = num3;
	third = num2;
      }
    // otherwise if num2 <= num1 AND num2 <= num 3
    } else if ( (num2<=num1) && (num2<=num3)) {
      // num2 is smallest
      first = num2;
      // order num1 and num3
      if (num1 <= num3) {
	// num1 is middle, num3 is largest
	second = num1;
	third = num3;
      } else {
	// num3 is middle, num1 is largest
	second = num3;
	third = num1;
      }
    } else { // now (num3<=num1) && (num3<=num2)
      // num3 is smallest
      first = num3;
      // order num1 and num2
      if (num1 <= num2) {
	// num1 is middle, num2 is largest
	second = num1;
	third = num2;
      } else {
	// num2 is middle, num1 is largest
	second = num2;
	third = num1;
      }
    }
    printf("smallest = %f, middle = %f, largest = %f\n", first, second, third);
  }
  return EXIT_SUCCESS;
}
