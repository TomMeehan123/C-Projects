 /*
 * Ex4-4-SalesPeople.c
 * sample solution to exercise 4.4: Write a C program that creates an 
 * array of 200 random gross salary values in the range 200 to 10,000
 * and then determines how many of the salespeople earned salaries in
 * each of the following ranges.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 200 // we'll discuss soon what this is :-)

int main() 
{
  int randomGross[SIZE]; // array of random gross sales
  int salaries[SIZE]; // array for calculated salaries
  // number of salespeople per range, initialised to 0
  int countRanges[9] = {0,0,0,0,0,0,0,0,0};
  int i; // loop variable

  // initialise random number generator
  srand(time(NULL));

  // fill random gross sales
  for (i=0; i<SIZE; ++i) {
    randomGross[i] = (rand()%9800) + 200;
  }
  
  // calculate salaries
  for (i=0; i<SIZE; ++i) {
    salaries[i] = 200 + (int) (0.09 * randomGross[i]);
  }
  
  // count salaries per range
  // use only of the alternatives
  // alternative 1: short version:
  for (i=0; i<SIZE; ++i) {
    countRanges[(salaries[i]/100)-2]++;
  }
  
  // print results
  printf("\n\n%i sales people earend in range €200 to €299\n", countRanges[0]);
  printf("%i sales people earend in range €300 to €399\n", countRanges[1]);
  printf("%i sales people earend in range €400 to €499\n", countRanges[2]);
  printf("%i sales people earend in range €500 to €599\n", countRanges[3]);
  printf("%i sales people earend in range €600 to €699\n", countRanges[4]);
  printf("%i sales people earend in range €700 to €799\n", countRanges[5]);
  printf("%i sales people earend in range €800 to €899\n", countRanges[6]);
  printf("%i sales people earend in range €900 to €999\n", countRanges[7]);
  printf("%i sales people earend €1000 or over\n\n", countRanges[8]);

  return EXIT_SUCCESS;
}
